#if 0
给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // 使用一个 vector<pair<int, int>> 来记录每行的军人数和行号
        vector<pair<int, int>> soldierCount;

        for (int i = 0; i < mat.size(); ++i) {
            int soldier = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 1) {
                    soldier++;
                } else {
                    break; // 因为每行是有序的，遇到第一个 0 后就可以结束
                }
            }
            soldierCount.emplace_back(soldier, i); // 记录军人数和行号
        }

        // 按军人数排序，若军人数相同，则按行号排序
        sort(soldierCount.begin(), soldierCount.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        // 取前 k 行的行号
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(soldierCount[i].second);
        }

        return result;
    }
};



class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // 使用一个vector<pair<int,int>>来统计军人的个数
        vector<pair<int, int>> soldierCount;
        for (int i = 0; i < mat.size(); ++i) {
            int l = 0, r = mat[i].size() - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (mat[i][mid] == 0) {
                    r = mid - 1;
                } else {
                    pos = mid;
                    l = mid + 1;
                }
            }
            soldierCount.emplace_back(pos + 1,i);
        }

        // 进行排序
        priority_queue q(greater<pair<int,int>>(),move(soldierCount));
            vector<int> ans;
            for (int i = 0; i < k; ++i) {
                ans.push_back(q.top().second);
                q.pop();
            }
            return ans;
    }
    };
#endif