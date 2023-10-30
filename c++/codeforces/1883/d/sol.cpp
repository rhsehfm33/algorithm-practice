#include <bits/stdc++.h>

using namespace std;

void solve() {
    int q;
    cin >> q;
    multiset<int> ls, rs;
    while (q--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == '+') {
            ls.insert(l);
            rs.insert(r);
        } else {
            ls.erase(ls.find(l));
            rs.erase(rs.find(r));
        }

        if (ls.size() > 1 and *rs.begin() < *ls.rbegin()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}