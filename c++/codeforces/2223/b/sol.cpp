#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int _ti;

struct Fenwick {
    int n;
    vector<int> tree;

    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void update(int i) {
        while (i <= n) {
            ++tree[i];
            i += i & -i;
        }
    }

    int query(int i) {
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }
};

struct ab {
    ll v;
    int ai, bi;
    ab(ll v, int ai, int bi) : v(v), ai(ai), bi(bi) {}
};

ll inv(ll num) {
    ll result = 1;
    ll exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * num) % MOD;
        }
        num = (num * num) % MOD;
        exp /= 2;
    }
    return result;
}

ll get_p(vector<ab>& sab, Fenwick& f, vector<int>& st) {
    ll p = 0;
    fill(f.tree.begin(), f.tree.end(), 0LL);
    sort(sab.begin(), sab.end(), [](auto& l, auto& r) {
        return l.v < r.v;
    });
    for (int i = sab.size() - 1, j = sab.size() - 1; i >= 0; i = j) {
        while (j >= 0 and sab[i].v == sab[j].v) {
            p += f.query(sab[j].ai - 1);
            st.push_back(sab[j].ai);
            --j;
        }
        while (st.size()) {
            f.update(st.back());
            st.pop_back();
        }
    }
    return p;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }

    vector<ll> fac(n + 1, 1);
    for (ll i = 2; i <= n; ++i) {
        fac[i] = (i * fac[i - 1]) % MOD;
    }
    vector<ab> sab;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sab.push_back({a[i] * b[j], i + 1, j + 1});
        }
    }

    Fenwick f(n);
    vector<int> st;
    ll p = get_p(sab, f, st);
    for (int bi = 0; bi < n; ++bi) {
        sab.clear();
        for (int ai = 0; ai < n; ++ai) {
            sab.push_back({a[ai] * b[bi], ai + 1, bi + 1});
        }
        p -= get_p(sab, f, st);
    }
    p %= MOD;
    p = (p * fac[n - 2]) % MOD;
    cout << (p * inv(fac[n]) % MOD) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}