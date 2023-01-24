#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    vector<int> b(n);
    for(auto& bi : b) {
        cin >> bi;
    }
    int m;
    cin >> m;
    multiset<int> xs;
    while (m--) {
        int xi;
        cin >> xi;
        xs.insert(xi);
    }

    stack<int> s;
    for (int i = 0; i < n; ++i) {
        if (b[i] > a[i]) {
            cout << "NO\n";
            return;
        }

        while (s.size() and b[i] > s.top()) {
            if (xs.find(s.top()) == xs.end()) {
                cout << "NO\n";
                return;
            }
            xs.erase(xs.find(s.top()));
            s.pop();
        }
        if (a[i] != b[i] and (s.empty() or b[i] < s.top())) {
            s.push(b[i]);
        }
    }

    while (s.size()) {
        if (xs.find(s.top()) == xs.end()) {
            cout << "NO\n";
            return;
        }
        xs.find(xs.erase(s.top()));
        s.pop();
    }

    cout << "YES\n";
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