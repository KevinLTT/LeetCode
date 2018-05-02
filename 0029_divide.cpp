#include "u.h"

class Solution {
    public:
        int divide(int dividend, int divisor)
        {
            const bool negative = (((dividend ^ divisor) >> 31) & 0x1) == 1;
            unsigned int quotient = 0;

            for (unsigned int a = dividend < 0 ? -dividend : dividend, b = divisor < 0 ? -divisor : divisor; a >= b;)
            {
                unsigned int k = 0;

                // We are looking for a k that b << k <= a but b << (k + 1) > a. The loop looks complicated since
                // we need to handle overflow. E.g. a == 1 << 31 and b == 1, k should be 31, because b << 31 == a
                // and b << 32 > a, however b << 32 actually overflows so b << 32 == 0, this loop will never end.
                // To prevent overflow, b << k must <= 0x80000000 / 2, otherwise, b << (k + 1) will overflow.
                for (; a >= b << k && b << k <= (0x80000000 >> 1); ++k);

                // When loop ends, if a < b << k, it means no overflow happens, and k increased one additional time, we
                // need to decrease k; otherwise (a >= b << k), it means overflow happens, k is the maximum we can find.
                quotient |= 1 << (a < b << k ? --k : k);
                a -= b << k;
            }

            // If negative is false, quotient must <= INT_MAX, otherwise overflow, should return INT_MAX.
            return negative ? 0 - quotient : quotient > INT_MAX ? INT_MAX : quotient;
        }
};
