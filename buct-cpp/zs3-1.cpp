//
// Created by hsy on 2024/9/23.
//
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<long long> l;
    long long t = 0;
    for (int i = 0; i < 12; ++i)
    {
        t = t * 10 + 1;
        l.push_back(t);
    }
    for (int i = 0; i < l.size(); ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                if (--n == 0)
                {
                    cout << l[i] + l[j] + l[k] << endl;
                    return 0;
                }
            }
        }
    }
}