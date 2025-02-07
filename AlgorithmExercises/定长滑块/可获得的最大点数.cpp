#if 0
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int point = n - k;
        int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(k == n) return totalSum;
        int sum = 0,num = numeric_limits<int>::max();
        for(int i = 0;i < n;++i){
            //进
            sum += cardPoints[i];
            if(i < point - 1) continue;
            num = min(sum,num);

            sum -= cardPoints[i - point + 1];

        }
        return totalSum - num;
    }
};

#endif