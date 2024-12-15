#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> res;
        string ln1 = "qwertyuiop", ln2 = "asdfghjkl", ln3 = "zxcvbnm";
        for (auto &word : words)
        {
            // 转换成小写
            string lowerWord = word;
            for (auto &i : lowerWord)
            {
                if (i >= 'A' && i <= 'Z')
                {
                    i += ('a' - 'A');
                }
            }
            int row1 = 0, row2 = 0, row3 = 0;
            for (auto &ch : lowerWord)
            {
                if (ln1.find(ch) != string::npos)
                {
                    row1 = 1;
                }
                else if (ln2.find(ch) != string::npos)
                {
                    row2 = 1;
                }
                else if (ln3.find(ch) != string::npos)
                {
                    row3 = 1;
                }
                if (row1 + row2 + row3 > 1)
                    break;
            }
            if (row1 + row2 + row3 == 1)
                res.push_back(word);
        }
        return res;
    };
};