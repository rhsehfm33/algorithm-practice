#include <bits/stdc++.h>

using namespace std;

typedef set<int> si;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<array<int, 2>>> vvai2;

int setsf(vvi& u2v, si& sa, vvai2& sf, int i, int pi) {
    if (sa.count(i)) {
        sf[i].push_back({0, i});
    }
    for (auto v : u2v[i]) {
        if (v == pi) {
            continue;
        }
        int result = setsf(u2v, sa, sf, v, i);
        if (result != -1) {
            sf[i].push_back({result, v});
        }
    }
    sort(sf[i].begin(), sf[i].end(), greater<array<int, 2>>());
    return sf[i].size() ? sf[i].front()[0] + 1 : -1;
}

void setans(vvi& u2v, si& sa, vvai2& sf, int pmx, int i, int pi, int& ans) {
    if (sa.count(i)) {
        pmx = max(pmx, 0);
    }
    
    pmx = max(pmx, sa.count(0) ? 0 : pmx);
    ans = min(ans, max(sf[i].size() ? sf[i].front()[0] : 0, pmx));
    for (auto v : u2v[i]) {
        if (v == pi) {
            continue;
        }

        if (sf[i].empty()) {
            setans(u2v, sa, sf, pmx + 1, v, i, ans);
        } else {
            if (sf[i][0][1] == v) {
                if (sf[i].size() > 1) {
                    setans(u2v, sa, sf, max(pmx + 1, sf[i][1][0] + 1), v, i, ans);
                } else {
                    setans(u2v, sa, sf, pmx + 1, v, i, ans);
                }
            } else {
                setans(u2v, sa, sf, max(pmx + 1, sf[i][0][0] + 1), v, i, ans);
            }
        }
    }
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    set<int> sa;
    for (int i = 0; i < k; ++i) {
        int ai;
        cin >> ai;
        sa.insert(ai);
    }
    vvi u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int ui, vi;
        cin >> ui >> vi;
        u2v[ui].push_back(vi);
        u2v[vi].push_back(ui);
    }

    int ans = 1e9;
    vvai2 sf(n + 1);
    setsf(u2v, sa, sf, 1, -1);
    setans(u2v, sa, sf, -1e9, 1, -1, ans);
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
