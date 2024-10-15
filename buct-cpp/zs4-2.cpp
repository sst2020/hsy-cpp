//
// Created by hsy on 2024/10/11.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, x, y;
    cin >> a >> b >> x >> y;

    // 直接从 a 到 b 的距离
    long long directDistance = abs(a - b);

    // 通过两个传送门的组合
    long long viaXandY = abs(a - x) + abs(y - b);
    long long viaYandX = abs(a - y) + abs(x - b);

    // 计算最小距离
    long long minDistance = min({directDistance, viaXandY, viaYandX});

    cout << minDistance << endl;
    return 0;
}