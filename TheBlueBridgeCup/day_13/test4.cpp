#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // 消耗掉cin >> n后的换行符

    unordered_map<int, int> unmap; // 统计每个ID的出现次数
    int min_id = INT_MAX;          // 记录最小ID
    int max_id = INT_MIN;          // 记录最大ID

    // 读取N行数据
    for (int i = 0; i < n; ++i)
    {
        string line;
        getline(cin, line);    // 读取整行
        stringstream ss(line); // 用stringstream分割
        int temp;
        while (ss >> temp) // 提取每行的每个整数
        {
            unmap[temp]++; // 统计出现次数
            if (temp < min_id)
                min_id = temp; // 更新最小ID
            if (temp > max_id)
                max_id = temp; // 更新最大ID
        }
    }

    int missing_id = -1;   // 断号
    int duplicate_id = -1; // 重号

    // 在min_id到max_id范围内查找断号和重号
    for (int id = min_id; id <= max_id; ++id)
    {
        if (unmap.find(id) == unmap.end()) // ID不在map中，即出现0次
        {
            missing_id = id; // 找到断号
        }
        else if (unmap[id] == 2) // ID出现2次
        {
            duplicate_id = id; // 找到重号
        }
    }

    // 输出结果
    cout << missing_id << " " << duplicate_id << endl;

    return 0;
}