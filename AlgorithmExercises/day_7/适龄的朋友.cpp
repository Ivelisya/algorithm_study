#if 0
在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。

如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：

ages[y] <= 0.5 * ages[x] + 7
ages[y] > ages[x]
ages[y] > 100 && ages[x] < 100
否则，x 将会向 y 发送一条好友请求。

注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。

返回在该社交媒体网站上产生的好友请求总数。

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // 先对年龄进行升序排序，便于二分搜索
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // 如果当前用户年龄过小，满足条件非常困难，直接跳过
            if(ages[i] <= 14) {
                continue;
            }

            // 计算能发送好友请求的最低年龄限制
            // ages[j] 必须严格大于 0.5 * ages[i] + 7
            // 故取 lower = floor(0.5 * ages[i] + 7) + 1
            int lower = static_cast<int>(0.5 * ages[i] + 7) + 1;

            // 使用二分查找找到 >= lower 的最左位置
            auto leftIt = std::lower_bound(ages.begin(), ages.end(), lower);

            // 使用二分查找找到 > ages[i] 的最左位置，因此 <= ages[i] 的范围在 [leftIt, rightIt - 1]
            auto rightIt = std::upper_bound(ages.begin(), ages.end(), ages[i]);

            // 满足范围的数量
            int count = rightIt - leftIt;

            // 自己不向自己发送请求，如果在范围内需要 -1
            // 条件：ages[i] >= lower 表示自己也计入了这个区间
            if(ages[i] >= lower) {
                count--;
            }

            // 累加该用户对其他用户的好友请求数
            ans += count;
        }

        return ans;
    }
};

#endif
