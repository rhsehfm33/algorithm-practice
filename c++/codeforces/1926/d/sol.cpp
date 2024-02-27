#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int ans = 0;

    int n;
    cin >> n;
    multiset<int> ms;
    while (n--) {
        int ai;
        cin >> ai;
        if (ms.count(INT_MAX ^ ai)) {
            ms.erase(ms.find(INT_MAX ^ ai));
        } else {
            ms.insert(ai);
            ++ans;
        }
    }

    cout << ans << '\n';
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