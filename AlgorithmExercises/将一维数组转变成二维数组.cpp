/*给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用
original 中 所有 元素创建一个 m 行 n 列的二维数组。

original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到
2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。

请你根据上述过程返回一个 m x n
的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。

输入：original = [1,2,3,4], m = 2, n = 2
输出：[[1,2],[3,4]]
解释：
构造出的二维数组应该包含 2 行 2 列。
original 中第一个 n=2 的部分为 [1,2] ，构成二维数组的第一行。
original 中第二个 n=2 的部分为 [3,4] ，构成二维数组的第二行。

输入：original = [1,2,3], m = 1, n = 3
输出：[[1,2,3]]
解释：
构造出的二维数组应该包含 1 行 3 列。
将 original 中所有三个元素放入第一行中，构成要求的二维数组。
*/
#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
  int size = original.size();
  if (size != (n * m))
    return vector<vector<int>>();
  vector<vector<int>> twoDArray;
  int index = 0;
  int row = n;

  // m为 vec的个数 n为vec内的元素个数
  while (m--) {
    vector<int> vec;
    n = row;
    while (n--) {
      vec.push_back(original[index]);
      index++;
    }
    twoDArray.push_back(vec);
  }
  return twoDArray;
  // m行 n列
}
// 官方解法
/*
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        if(original.size() != m*n)
            return ans;
        for(auto it = original.begin();it != original.end();it += n){
            ans.emplace_back(it,it+n);
        }
        return ans;
    }
*/