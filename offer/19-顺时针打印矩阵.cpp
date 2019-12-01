class Solution { // 该答案来自yxc大佬，欢迎去AcWing浏览。
public:
    vector<int> printMatrix(vector<vector<int>>& mat) {
        vector<int> res;
        if (mat.empty()) return res;
        vector<vector<bool>> st(n, vector<bool>(m, false)); // 定义一个状态，判断当前坐标是否被访问过
        int n = mat.size(), m = mat[0].size();
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // x 和 y 的上下左右方向
        int x = 0, y = 0, d = 1; // x 和 y 的初始方向
        for (int i = 0; i < n*m; ++i) { // 遍历所有点
            res.push_back(mat[x][y]); // 保存第一坐标位置
            st[x][y] = true; // 此时第一个坐标已经访问过

            int a = x + dx[d], b = y + dy[d]; // 顺时针方向
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) { // 各种边界条件的判断
                d = (d + 1) % 4; // 遇到边角要转换方向
                a = x + dx[d], b = y + dy[d]; // 继续顺时针方向走
            }
            x = a, y = b; // 更新最终的坐标位置
        }
        return res;
    }
};



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
