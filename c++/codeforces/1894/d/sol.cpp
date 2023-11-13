#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;

    list<int> a;
    map<int, list<int>::iterator> ai2ait;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        auto ait = a.insert(a.end(), ai);
        ai2ait[ai] = ait;
    }
    vector<int> b(m);
    for (auto& bi : b) {
        cin >> bi;
    }

    sort(b.begin(), b.end());
    for (int bi : b) {
        auto ait = ai2ait.lower_bound(bi);
        if (ait != ai2ait.end()) {
            a.insert(next(ait->second), bi);
        } else {
            a.push_front(bi);
        }
    }

    for (int ai : a) {
        cout << ai << ' ';
    }
    cout << '\n';
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