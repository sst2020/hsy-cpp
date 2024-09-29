//
// Created by hsy on 2024/9/6.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        vector<int>arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        vector<int> a(n + 1);
        for (int i = 0; i < n + 1; ++i)
        {
            if (i < n)
            {
                a[i] = arr[i];
            }
            else if (i == n)
            {
                a[i] = m;
            }
        }
        for (int i = 0; i < n + 1; ++i)
        {
            for (int j = 0; j < n + 1; ++j)
            {
                if (a[i] < a[j])
                {
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
        for (int i = 0; i < n + 1; ++i)
        {
            cout << a[i] << " ";
        }
        printf("\n");
    }
    return 0;
}
