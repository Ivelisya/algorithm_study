#if 0
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
const int MX = 34;
vector<int> c[MX];
 auto init = []() {
    for (int i = 0; i < MX; i++) {
        c[i].resize(i + 1, 1);
        for (int j = 1; j < i;j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        } 
    }
     return 0;
}();
class Solution {
public:
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1

    vector<int> getRow(int rowIndex) {
        return c[rowIndex];
    }
};
#endif