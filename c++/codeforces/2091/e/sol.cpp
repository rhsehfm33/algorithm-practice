#include <bits/stdc++.h>
using namespace std;

int _ti;
const int MAX = 1e7;
vector<int> p(MAX + 1, 1);

void preset() {
    p[0] = p[1] = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (p[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= MAX; j += i) {
            p[j] = 0;
        }
    }
    for (int i = 2; i <= MAX; ++i) {
        p[i] += p[i - 1];
    }
}

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i * 2 <= n; ++i) {
        ans += p[n / i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}