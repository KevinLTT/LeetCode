class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        
        int xStep[4] = {1, 0, -1, 0};
        int yStep[4] = {0, 1, 0, -1};
        int x = 0, y = 0;
        int state = 0;
        int traversed = 0x80000006;
        while(1)
        {
            if( x >= matrix[0].size() || y >= matrix.size() || matrix[y][x] == traversed)
                break;
            
            res.push_back(matrix[y][x]);
            matrix[y][x] = traversed;
            if(x + xStep[state] >= matrix[0].size() || y + yStep[state] >= matrix.size() || matrix[y + yStep[state]][x + xStep[state]] == traversed)      
                state = (state + 1) % 4;
            x += xStep[state];
            y += yStep[state];
        };   
        
        return res;
    }
};
