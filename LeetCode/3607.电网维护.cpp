/*
 * @lc app=leetcode.cn id=3607 lang=cpp
 *
 * [3607] 电网维护
 */
#include <iostream>
#include <vector>
#include <numeric> // For std::iota
#include <set>     // For std::set
#include <map>     // For std::map

// 修正 typo: uisng -> using
using namespace std;

// @lc code=start

// ============================================================================
// 并查集 (Disjoint Set Union) 实现
// 带有路径压缩和按秩合并优化
// ============================================================================
class DSU {
public:
    vector<int> parent;
    vector<int> rank; // 用于按秩合并，优化树的深度

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // 初始化：每个元素的父节点是它自己
        rank.assign(n + 1, 0); // 初始化秩为0
    }

    // 查找操作：查找元素 v 的根节点，并进行路径压缩
    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]); // 路径压缩
    }

    // 合并操作：合并元素 a 和 b 所在的集合
    // 返回 true 如果成功合并了两个不同的集合，否则返回 false
    bool unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a != root_b) {
            // 按秩合并：将秩较小的树连接到秩较大的树上
            if (rank[root_a] < rank[root_b]) {
                swap(root_a, root_b);
            }
            parent[root_b] = root_a;
            if (rank[root_a] == rank[root_b]) {
                rank[root_a]++;
            }
            return true;
        }
        return false; // 已经在同一个集合中
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // 1. 初始化并查集
        DSU dsu(c);

        // 2. 构建电网结构：处理所有连接
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        // 3. 初始化电站在线状态
        // is_online[i] 为 true 表示电站 i 在线，false 表示离线
        vector<bool> is_online(c + 1, true);

        // 4. 初始化每个电网中在线电站的集合
        // map 的键是电网的根节点 ID，值是一个有序集合，存储该电网中所有在线电站的 ID
        map<int, set<int>> component_online_stations;

        // 遍历所有电站，将其加入到其所属电网的在线电站集合中
        for (int i = 1; i <= c; ++i) {
            int root = dsu.find(i); // 找到电站 i 所属电网的根节点
            component_online_stations[root].insert(i);
        }

        // 5. 处理查询
        vector<int> results;
        for (const auto& query : queries) {
            int type = query[0];
            int station_id = query[1];

            if (type == 1) { // 类型 1: 请求维护检查
                if (is_online[station_id]) {
                    // 电站在线，自行解决
                    results.push_back(station_id);
                } else {
                    // 电站离线，由电网中编号最小的在线电站解决
                    int root = dsu.find(station_id); // 找到电站所属电网的根节点
                    // 检查该电网是否存在且有在线电站
                    if (component_online_stations.count(root) && !component_online_stations[root].empty()) {
                        // 该电网存在在线电站，取最小的那个
                        results.push_back(*component_online_stations[root].begin());
                    } else {
                        // 该电网中不存在任何在线电站
                        results.push_back(-1);
                    }
                }
            } else { // 类型 2: 电站离线
                // 只有当电站当前在线时才执行离线操作，避免重复处理或错误状态
                if (is_online[station_id]) {
                    is_online[station_id] = false; // 设置为离线
                    int root = dsu.find(station_id); // 找到电站所属电网的根节点
                    // 从该电网的在线电站集合中移除此电站
                    // 确保 root 存在于 map 中，虽然理论上它应该存在
                    if (component_online_stations.count(root)) {
                        component_online_stations[root].erase(station_id);
                    }
                }
            }
        }

        return results;
    }
};
// @lc code=end
