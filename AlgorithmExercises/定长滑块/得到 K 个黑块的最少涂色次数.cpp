#if 0
给你一个长度为 n 下标从 0 开始的字符串 blocks ，blocks[i] 要么是 'W' 要么是 'B' ，表示第 i 块的颜色。字符 'W' 和 'B' 分别表示白色和黑色。

给你一个整数 k ，表示想要 连续 黑色块的数目。

每一次操作中，你可以选择一个白色块将它 涂成 黑色块。

请你返回至少出现 一次 连续 k 个黑色块的 最少 操作次数。
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0,ans = 0;
        //计数 k 内 w 的 最少个数
        for(int i = 0;i < blocks.size();++i){
            //进来
            if(blocks[i] == 'W') count++;
            if(i < k - 1) continue;
            if(i == k - 1) ans = count; //当刚好为k时的操作数
            ans = min(ans,count);
            //出去
            if(blocks[i - k+ 1] == 'W') count--;
        }
        return ans;
    }
};
#endif