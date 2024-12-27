/*
给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表，用字母 A 到 Z
表示，以及一个冷却时间
n。每个周期或时间间隔允许完成一项任务。任务可以按任何顺序完成，但有一个限制：两个
相同种类 的任务之间必须有长度为 n 的冷却时间。

返回完成所有任务所需要的 最短时间间隔 。
*/
#if 0
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 计算出频率
        unordered_map<char, int> tasksCount;
        for (auto task : tasks) {
            tasksCount[task]++;
        }
        // 根据频率排序
        vector<int> frequence;
        for (auto& [first, second] : tasksCount) {
            frequence.push_back(second);
        }
        int maxCount = *max_element(frequence.begin(), frequence.end());
        int maxCountTasks = count(frequence.begin(), frequence.end(), maxCount);
        
        // 计算最短时间
        int intervalTime = (maxCount - 1) * (n + 1) + maxCountTasks;
        return max((int)tasks.size(), intervalTime);
    }
};

#endif