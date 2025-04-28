#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    vector<int> sorted_vec;
    sorted_vec.reserve(N); // 预分配内存，提高效率

    for (int i = 0; i < vec.size(); ++i)
    {
        int temp = vec[i];
        bool inserted = false;
        for (int j = 0; j < sorted_vec.size(); ++j)
        {
            if (temp < sorted_vec[j])
            {
                sorted_vec.insert(sorted_vec.begin() + j, temp);
                inserted = true;
                break; // 插入后就退出内层循环
            }
        }
        if (!inserted)
        {
            sorted_vec.push_back(temp); // 如果比所有已排序的元素都大，则添加到末尾
        }
    }

    for (int i = 0; i < sorted_vec.size(); ++i)
    {
        cout << sorted_vec[i] << (i == sorted_vec.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
