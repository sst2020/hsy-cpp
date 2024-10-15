#include <bits/stdc++.h>
using namespace std;
int arr[100010];
bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int key;
        cin >> key;
        int r = n - 1, l = 0, mid;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (arr[mid] > key)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        int ans = abs(arr[l] - key) > abs(arr[r] - key) ? r : l;
        cout << arr[ans] << endl;
    }
}