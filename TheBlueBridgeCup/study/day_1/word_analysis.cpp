/*
题目描述
小蓝正在学习一门神奇的语言，这门语言中的单词都是由小写英文字母组 成，有些单词很长，远远超过正常英文单词的长度。小蓝学了很长时间也记不住一些单词，他准备不再完全记忆这些单词，而是根据单词中哪个字母出现得最多来分辨单词。

现在，请你帮助小蓝，给了一个单词后，帮助他找到出现最多的字母和这 个字母出现的次数。

输入描述
输入一行包含一个单词，单词只由小写英文字母组成。

对于所有的评测用例，输入的单词长度不超过 1000。

输出描述
输出两行，第一行包含一个英文字母，表示单词中出现得最多的字母是哪 个。如果有多个字母出现的次数相等，输出字典序最小的那个。

第二行包含一个整数，表示出现得最多的那个字母在单词中出现的次数。
*/
#include <iostream>
#include <string>

using namespace std;
int main()
{
  int alphabet[26] = {0};
  string arr;
  cin >> arr;
  for (auto &ch : arr)
  {
    alphabet[ch - 'a']++;
  }
  int mx = 0;
  int mx_index = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (alphabet[i] > mx)
    {
      mx = alphabet[i];
      mx_index = i;
    }
  }
  cout << char(mx_index + 'a') << endl;
  cout << mx;
  return 0;
}