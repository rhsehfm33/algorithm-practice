#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    vector<pair<int, list<int>::iterator>> vec;
    int n;
    cin >> n;
    list<int> li;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        li.push_back(ai);
        vec.push_back({ai, prev(li.end())});
    }
    sort(vec.begin(), vec.end(), [] (auto& l, auto& r) {
        return l.first < r.first;
    });

    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        auto lit = vec[i].second;
        auto llit = lit == li.begin() ? prev(li.end()) : prev(lit);
        auto rlit = lit == prev(li.end()) ? li.begin() : next(lit);
        ans += min(*llit, *rlit);
        li.erase(lit);
    }
    cout << ans << '\n';
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