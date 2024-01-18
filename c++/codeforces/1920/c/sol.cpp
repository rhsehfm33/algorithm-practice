#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> d;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) {
                d.push_back(n / i);
            }
        }
    }

    int ans = 0;
    for (int di : d) {
        int g = 0;
        for (int i = 0; i < di and g != 1; ++i) {
            for (int j = i + di; j < n and g != 1; j += di) {
                g = gcd(g, abs(a[i] - a[j]));
            }
        }
        ans += (g != 1);
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