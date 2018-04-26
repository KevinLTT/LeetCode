#pragma once
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode( int x ) : val(x), next(nullptr) {}
};
