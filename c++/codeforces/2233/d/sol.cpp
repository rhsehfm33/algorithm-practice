#include <bits/stdc++.h>
using namespace std;

int _ti;

bool check_swap(vector<int> a, int i, int j) {
    set<int> vis;
    swap(a[i], a[j]);
    for (int i = 0; i < a.size(); ++i) {
        if (i and a[i - 1] != a[i] and vis.count(a[i])) {
            return false;
        }
        vis.insert(a[i]);
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int t = -1;
    set<int> vis;
    for (int i = 0; i < n; ++i) {
        if (i and a[i] != a[i - 1] and vis.count(a[i])) {
            t = a[i];
            break;
        }
        vis.insert(a[i]);
    }
    if (t == -1) {
        cout << "YES\n";
        return;
    }

    set<int> s;
    for (int i = 0; i < n; ++i) {
        if (a[i] == t) {
            s.insert(i);
        }
    }

    int sl = s.size();
    for (int i = 0, swp = -1; i < n; ++i) {
        if (a[i] == t) {
            s.erase(i);
        } else {
            swp = i;
        }
        if (i - sl >= 0 and a[i - sl] == t) {
            s.insert(i - sl);
        }
        if (i >= sl - 1 and s.size() == 1 and check_swap(a, *s.begin(), swp)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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