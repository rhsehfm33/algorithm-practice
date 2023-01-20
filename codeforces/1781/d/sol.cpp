#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isSquare(ll num) {
    ll square = (ll)round(sqrt(num));
    return square * square == num;
}

ll dfs(vector<ll>& a, ll i, vector<map<ll, ll>>& dp, ll curNum) {
    if (i == a.size() - 1) {
        return 0;
    }
    if (dp[i].count(curNum)) {
        return dp[i][curNum];
    }

    for (int j = i + 1; j < a.size(); ++j) {
        ll nextNum = curNum + (a[j] - a[i]);
        if (isSquare(nextNum)) {
            dp[i][curNum] = max(dp[i][curNum], 1 + dfs(a, j , dp, nextNum));
        }
    }
    return dp[i][curNum];
}

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    vector<map<ll, ll>> dp(n);

    ll ans = 1;
    for (ll i = 0; i < n - 1; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            ll diff = a[j] - a[i];

            for (ll k = 1; k * k < diff; ++k) {
                if (diff % k != 0) {
                    continue;
                }

                ll left = k;
                ll right = diff / k;
                if ((right - left + 1) % 2 == 0) {
                    continue;
                }

                ll y = (left + right) / 2;
                ll x = y - left;
                ll curNum = x * x;
                ll nextNum = y * y;
                if (curNum >= a[i] and curNum - a[i] == nextNum - a[j]) {
                    dp[i][curNum] = max(dp[i][curNum], 1 + dfs(a, j, dp, nextNum));
                    ans = max(ans, 1 + dp[i][curNum]);
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