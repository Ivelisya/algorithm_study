int nToten(int key, int n)
{
    int bit = 0;
    int ans = 0;
    while (key > 0)
    {
        int temp = key % 10;
        key /= 10; // 先除以10

        if (bit > 0)
        {
            int multiplier = 1;
            for (int i = 1; i <= bit; i++)
            {
                multiplier *= 9;
            }
            ans += temp * multiplier;
        }
        else
        {
            ans += temp;
        }

        bit++;
    }
    return ans;
}
