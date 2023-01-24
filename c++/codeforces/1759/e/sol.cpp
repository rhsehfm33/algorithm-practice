#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 2e5;

ll dp[2][3][MAX + 1];

void init(int n) {
    for (int b = 0; b <= 1; ++b) {
        for (int g = 0; g <= 2; ++g) {
            for (int i = 0; i <= n; ++i) {
                dp[b][g][i] = -1;
            }
        }
    }
}

void solve(int _ti) {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    init(n);
    dp[1][2][0] = h;
    for (ll i = 0; i < n; ++i) {
        for (ll b = 0; b <= 1; ++b) {
            for (ll g = 0; g <= 2; ++g) {
                if (dp[b][g][i] == -1) {
                    continue;
                }
                ll ch = dp[b][g][i];
                ll added = (a[i] / 2ll);
                if (a[i] < ch) {
                    dp[b][g][i + 1] = max(dp[b][g][i + 1], dp[b][g][i] + added);
                    ans = i + 1;
                }
                if (ch * 2 > a[i] and g) {
                    dp[b][g - 1][i + 1] = max(dp[b][g - 1][i + 1], dp[b][g][i] * 2 + added);
                    ans = i + 1;
                }
                if (ch * 3 > a[i] and b) {
                    dp[b - 1][g][i + 1] = max(dp[b - 1][g][i + 1], dp[b][g][i] * 3 + added);
                    ans = i + 1;
                }
                if (ch * 4 > a[i] and g == 2) {
                    dp[b][g - 2][i + 1] = max(dp[b][g - 2][i + 1], dp[b][g][i] * 4 + added);
                    ans = i + 1;
                }
                if (ch * 6 > a[i] and g and b) {
                    dp[b - 1][g - 1][i + 1] = max(dp[b - 1][g - 1][i + 1], dp[b][g][i] * 6 + added);
                    ans = i + 1;
                }
                if (ch * 12 > a[i] and g == 2 and b) {
                    dp[b - 1][g - 2][i + 1] = max(dp[b - 1][g - 2][i + 1], dp[b][g][i] * 12 + added);
                    ans = i + 1;
                }
            }        
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