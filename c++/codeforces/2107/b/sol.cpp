#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k, b = 0;
    cin >> n >> k;
    multiset<int> ms;
    while (n--) {
        int ai;
        cin >> ai;
        ms.insert(ai);
        b ^= (ai & 1);
    }
    ms.insert(*ms.rbegin() - 1);
    ms.erase(prev(ms.end()));
    if (*ms.rbegin() - *ms.begin() > k || !b) {
        cout << "Jerry\n";
    } else {
        cout << "Tom\n";
    }
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