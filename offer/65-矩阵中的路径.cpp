#include <iostream>

class Solution {
public:
    bool hasPath(char *matrix, int rows, int cols, char *str) {
        bool flag[] = new bool(rows*cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (helper(matrix, i, j, rows, cols, str, 0, flag)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(char *matrix, int i, int j, int rows, int cols, char *str, int k, bool flag) {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == true) {
            return false;
        }
        if (k == str.strlen() - 1) return true;
        flag[index] = true;
        if (helper(matrix, i-1, j, rows, cols, str, k+1, flag) || helper(matrix, i+1, j, rows, cols, str, k+1, flag) || 
            helper(matrix, i, j-1, rows, cols, str, k+1, flag) || helper(matrix, i, j+1, rows, cols, str, k+1, flag)) {
            return true;
        }

        flag[index] = false;
        return false;
    }
};
