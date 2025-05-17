#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a[2];
    list<int> l;
    vector<list<int>::iterator> v(n + 1);
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        a[i % 2].push_back(ai);
        v[ai] = l.insert(l.end(), ai);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    for (int i = 0; l.size() >= 4; ++i) {
        auto ait = v[a[i % 2][i / 2]];
        cout << *ait << ' ';
        bool is_last = next(ait) == l.end();
        auto nait = is_last ? prev(ait) : next(ait);
        v[*nait] = l.insert(l.begin(), *nait);
        l.erase(nait);
        l.erase(ait);
        if (is_last) {
            iter_swap(l.begin(), next(next(l.begin())));
            swap(v[*l.begin()], v[*next(next(l.begin()))]);
        }
    }
    while (l.size()) {
        cout << *l.begin() << ' ';
        l.pop_front();
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