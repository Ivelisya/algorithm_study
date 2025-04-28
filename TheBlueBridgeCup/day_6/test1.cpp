#include <iostream>
using namespace std;
int two = 0;
int main()
{
    for (int i = 1; i <= 2020; ++i)
    {
        int temp = i;
        while (temp > 0)
        {
            if (temp % 10 == 2)
                two++;
            temp /= 10;
        }
    }
    cout << two;
}