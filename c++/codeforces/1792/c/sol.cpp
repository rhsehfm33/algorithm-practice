#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<list<int>::iterator> pi2it(n + 1);
    list<int> li;
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        li.push_back(pi);
        pi2it[pi] = prev(li.end());
    }

    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (li.front() != i + 1 or li.back() != n - i) {
            ans = i + 1;
        }
        li.erase(pi2it[i + 1]);
        li.erase(pi2it[n - i]);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}