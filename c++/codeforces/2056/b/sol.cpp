#include <bits/stdc++.h>

using namespace std;

int _ti;

vector<int> dnq(vector<string>& g, vector<int> v) {
    if (v.size() <= 1) {
        return v;
    }

    vector<int> lv, rv;
    for (int i = 1; i < v.size(); ++i) {
        if (g[v[0]][v[i]] == '0') {
            lv.push_back(v[i]);
        } else {
            rv.push_back(v[i]);
        }
    }
    lv = dnq(g, lv);
    rv = dnq(g, rv);
    lv.push_back(v[0]);
    lv.insert(lv.end(), rv.begin(), rv.end());
    return lv;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        v[i] = i;
    }
    for (auto pi : dnq(g, v)) {
        cout << pi + 1 << ' ';
    }
    cout << '\n';
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