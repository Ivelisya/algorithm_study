#if 0
有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。

在某些分钟内，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。

当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。

请你返回 这一天营业下来，最多有多少客户能够感到满意 。
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 基础满意值加窗口内最大的额外满意值
        int baseSatisfaction = 0, extraSatisfaction = 0,
            maxExtraSatisfaction = 0;
        for (int i = 0; i < grumpy.size(); ++i) {
            // 进
            grumpy[i] == 1 ? extraSatisfaction += customers[i]
                           : baseSatisfaction += customers[i];
            if (i < minutes - 1)
                continue;
            maxExtraSatisfaction = max(maxExtraSatisfaction, extraSatisfaction);
            // 出
            grumpy[i - minutes + 1] == 1
                ? extraSatisfaction -= customers[i - minutes + 1]
                : extraSatisfaction;
        }
        return baseSatisfaction + maxExtraSatisfaction;
    }
};
#endif