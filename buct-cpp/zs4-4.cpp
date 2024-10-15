#include <bits/stdc++.h>
using namespace std;
class LazySegTree
{
private:
    long long N{};
    vector<long long> seg, lazy;
    void push(long long id, long long tl, long long tr)
    {
        seg[id] += lazy[id];
        if (tl != tr)
        {
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
        }
        lazy[id] = 0;
    }
    void upd(long long id, long long tl, long long tr, long long L, long long R, long long val)
    {
        push(id, tl, tr);
        if (tl > R || tr < L)
        {
            return;
        }
        if (L <= tl && tr <= R)
        {
            lazy[id] += val;
            push(id, tl, tr);
            return;
        }
        upd(id << 1, tl, (tl + tr) >> 1, L, R, val);
        upd(id << 1 | 1, ((tl + tr) >> 1) + 1, tr, L, R, val);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
    }
    long long query(long long id, long long tl, long long tr, long long L, long long R)
    {
        if (L == 0 && R == 0)
        {
            return 0;
        }
        push(id, tl, tr);
        if (tl > R || tr < L)
        {
            return 1e9;
        }
        if (tl >= L && tr <= R)
        {
            return seg[id];
        }
        return min(query(id << 1, tl, (tl + tr) >> 1, L, R), query(id << 1 | 1, ((tl + tr) >> 1) + 1, tr, L, R));
    }
public:
    LazySegTree() = default;
    explicit LazySegTree(long long N): N(N), seg(4 * (N + 1), 0), lazy(4 * (N + 1), 0) {}
    void upd(long long L, long long R, long long val)
    {
        upd(1, 1, N, L, R, val);
    }
    long long query(long long L, long long R)
    {
        return query(1, 1, N, L, R);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long n, q;
    cin >> n >> q;
    LazySegTree st(n);
    string s;
    cin >> s;
    long long cur = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '(')
        {
            cur++;
        }
        else
        {
            cur--;
        }
        st.upd(i, i, cur);
    }
    while (q--)
    {
        long long op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            if (s[l - 1] == s[r - 1])
            {
                continue;
            }
            if (s[l - 1] == '(')
            {
                st.upd(l, r - 1, -2);
            }
            else
            {
                st.upd(l, r - 1, 2);
            }
            swap(s[l - 1], s[r - 1]);
        }
        else
        {
            long long a = st.query(l - 1, l - 1), b = st.query(r, r), c = st.query(l, r);
            if (a == b and a <= c)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
    }
    return 0;
}