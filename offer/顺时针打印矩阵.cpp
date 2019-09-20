#include <iostream>

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        if (row == 0 || col == 0) return res;
        int left = 0, top = 0, right = col-1, down = row-1;
        while (left <= right && top <= down) {
            for (int i = left; i <= right; ++i) { // left -> right
                res.push_back(matrix[top][i]);
            }
            for (int i = top+1; i <= down; ++i) { // top -> down
                res.push_back(matrix[i][right]);
            }
            for (int i = right-1; i >= left; --i) { // right -> left
                res.push_back(matrix[down][i]);
            }
            for (int i = down-1; i > top; --i) { // down -> top
                res.push_back(matrix[i][left]);
            }
            left++;
            top++;
            right--;
            bottom--;
        }
        return res;
    }
};
