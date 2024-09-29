//
// Created by hsy on 2024/9/7.
//
#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    vector < vector<int>> ans;
    for (int i = 0; i < 1 << n; ++i)
    {
        vector<int> vv;
        for (int j = 0; j < n; ++j)
        {
            if (i >> j & 1)
            {
                vv.push_back(v[j]);
            }
        }
        ans.push_back(vv);
    }
    sort(ans.begin(), ans.end());
    for (const auto& a : ans)
    {
        for (auto x : a)
        {
            cout << x << " ";
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}