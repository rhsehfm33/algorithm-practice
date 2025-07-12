#include <bits/stdc++.h>
using namespace std;

int _ti;


void solve() {
    int n, k;
    cin >> n >> k;
    multiset<int> ms;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ms.insert(ai);
        if (ms.size() >= k) {
            ms.erase(prev(ms.end()));
        }
    }
    if (k <= 2) {
        cout << "YES\n";
        return;
    }

    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (ms.find(a[i]) != ms.end()) {
            b.push_back(a[i]);
        }
    }

    auto ms_del = [&](int k) -> void {
        auto it = ms.find(k);
        if (it != ms.end()) {
            ms.erase(it);
        }
    };

    int me = *ms.rbegin();
    for (int l = 0, r = b.size() - 1; l <= r; ++l, --r) {
        if (b[l] == me and b[r] == me) {
            ms_del(me);
            if (l != r) {
                ms_del(me);
            }
        } else if (b[l] == me) {
            ++r;
        } else if (b[r] == me) {
            --l;
        } else if (b[l] == b[r]) {
            ms_del(b[l]);
            if (l != r) {
                ms_del(b[l]);
            }
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << (ms.empty() ? "YES\n" : "NO\n");
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