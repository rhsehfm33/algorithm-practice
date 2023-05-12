#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll MAX = 1e6;
 
vector<vector<ll>> presum;
vector<pair<int, int>> location;
 
void preset() {
    presum.resize(2000);
    location.resize(MAX + 1);
    for (ll i = 1, j = 0; i <= MAX; ) {
        for (ll k = i; k <= i + j and k <= MAX; ++k) {
            presum[j].push_back(k * k);
            location[k] = {j, k - i};
        }
 
        for (ll k = 1; k < presum[j].size(); ++k) {
            presum[j][k] += presum[j][k - 1];
        }
 
        i += ++j;
    }
}
 
void solve(int _ti) {
    int n;
    cin >> n;
 
    ll ans = 0;
    int cnt = 1;
    auto [x, y] = location[n];
    while (x >= 0) {
        int ly = max(0, y - cnt);
        int ry = min((int)presum[x].size() - 1, y);
        if (y - cnt >= 0) {
            ans += (presum[x][ry] - presum[x][ly]);
        }
        else {
            ans += presum[x][ry];
        }
        --x;
        ++cnt;
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    preset();
 
    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}