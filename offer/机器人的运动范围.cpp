#include <iostream>

int movingCount(int threshold, int row, int col) {
    int flag[row][col];
    return helper(threshold, 0, 0, row, col, flag);
}

int helper(int threshold, int i, int j, int row, int col, int flag[][]) {
    if (i < 0 || i >= row || j < 0 || j >= col || sum(i) + sum(j) > threshold || flag[i][j] == 1) {
        return 0;
    }
    flag[i][j] = 1;
    return helper(threshold, i-1, j, row, col, flag) +
        helper(threshold, i+1, j, row, col, flag) +
        helper(threshold, i, j-1, row, col, flag) +
        helper(threshold, i, j+1, row, col, flag) + 1;
}

int sum(int i) {
    int ans = 0;
    while ((i /= 10) > 0) {
        ans += i % 10;
    }
    return ans;
}

