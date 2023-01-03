#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll MOD = 998244353;

struct DJS {
    vector<int> par;
    vector<int> cnt_v;
    vector<int> cnt_e;
    vector<int> is_double;

    DJS() {

    }

    DJS(int n) {
        for (int i = 0; i < n; ++i) {
            par.push_back(i);
            cnt_v.push_back(1);
            cnt_e.push_back(0);
            is_double.push_back(0);
        }
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            cnt_e[x] += 1;
            return;
        }
        if (x > y) {
            swap(x, y);
        }

        par[y] = x;
        cnt_v[x] += cnt_v[y];
        cnt_e[x] += cnt_e[y];
        cnt_e[x] += 1;
        is_double[x] |= is_double[y];
    }
};
 
void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }

    DJS djs(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            djs.is_double[a[i]] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        djs.merge(a[i], b[i]);
    }

    ll ans = 1;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        int root = djs.find(a[i]);
        if (vis[root]) {
            continue;
        }
        vis[root] = true;

        if (djs.cnt_e[root] != djs.cnt_v[root]) {
            cout << "0\n";
            return;
        }

        if (djs.is_double[root]) {
            ans = (ans * n) % MOD;
        }
        else {
            ans = (ans * 2) % MOD;
        }
    }
    
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }
 
    return 0;
}