#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& di : d) {
        cin >> di;
    }

    list<int> li;
    queue<int> q;
    map<int, list<int>::iterator> m;
    for (int i = 0; i < n; ++i) {
        m[i] = li.insert(li.end(), i);
        q.push(i);
    }

    for (int i = 0; i < n; ++i) {
        set<int> s;
        queue<int> q2;
        int ql = q.size();
        while (ql--) {
            auto idx = q.front(); q.pop();
            auto it = m[idx];
            int a1 = it != li.begin() ? a[*prev(it)] : 0;
            int a2 = next(it) != li.end() ? a[*next(it)] : 0;
            if (d[*it] - (a1 + a2) < 0) {
                s.insert(*it);
                if (it != li.begin()) {
                    q2.push(*prev(it));
                }
                if (next(it) != li.end()) {
                    q2.push(*next(it));
                }
            }
        }

        cout << s.size() << ' ';
        while (q2.size()) {
            auto idx = q2.front(); q2.pop();
            if (!s.count(idx)) {
                q.push(idx);
            }
        }
        for (auto idx : s) {
            li.erase(m[idx]);
        }
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