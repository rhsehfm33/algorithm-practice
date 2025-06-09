#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;
ll MAX = 1e6;
vector<vector<int>> f(MAX + 1);

void preset() {
    for (int i = MAX; i > 1; --i) {
        for (int j = i; j <= MAX; j +=i) {
            f[j].push_back(i);
        }
    }
}

int bfs(vector<int>& f, int num, int k) {
    int c = 0;
    vector<bool> s(num + 1);
    queue<int> q;
    q.push(num);
    while (q.size()) {
        int ql = q.size();
        while (ql--) {
            int cn = q.front();
            q.pop();
            if (cn == 1) {
                return c;
            }
            for (auto& fi : f) {
                if (fi <= k and cn % fi == 0 and !s[cn / fi]) {
                    s[cn / fi] = true;
                    q.push(cn / fi);
                }
            }
        }
        ++c;
    }
    return -1;
}

void solve() {
    ll x, y, k, ans = 0;
    cin >> x >> y >> k;
    int m1 = lcm(x, y) / x;
    int r1 = bfs(f[m1], m1, k);
    int m2 = lcm(x, y) / y;
    int r2 = bfs(f[m2], m2, k);
    if (r1 == -1 or r2 == -1) {
        cout << "-1\n";
        return;
    }
    cout << r1 + r2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}