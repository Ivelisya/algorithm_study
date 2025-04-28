#include <bits/stdc++.h>
using namespace std;
int tenTon(int key, int n)
{
    if (key == 0)
    {
        return 0;
    }
    int ans = 0;
    long long place_value = 1;
    while (key > 0)
    {
        int remainder = key % n;
        ans += remainder * place_value;
        place_value *= 10;
        key /= n;
    }
    return ans;
}
int nToten(int key, int n)
{
    int bit = 0;
    int ans = 0;
    while (key > 0)
    {
        int temp = key % 10;
        ans += temp * pow(n, bit);
        bit++;
        key /= 10;
    }
    return ans;
}
int main()
{
    return cout << nToten(2022, 9) << " " << tenTon(nToten(2022, 9), 9), 0;
    // return cout << nToten(2022, 9), 0;
}