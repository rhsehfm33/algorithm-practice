#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    priority_queue<int, vector<int>, less<int>> l;
    priority_queue<int, vector<int>, greater<int>> r;
    for (int i = 0; i < n; ++i) {
        while (l.size() and l.top() > a[i]) {
            r.push(l.top() + 1);
            l.pop();
        }
        l.push(a[i]);
    }
    
    while (l.size()) {
        if (r.size() and l.top() > r.top()) {
            r.push(l.top() + 1);
        } else {
            r.push(l.top());
        }
        l.pop();
    }
    while (r.size()) {
        cout << r.top() << ' ';
        r.pop();
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