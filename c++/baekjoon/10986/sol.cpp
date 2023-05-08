#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (auto& Ai : A) {
        cin >> Ai;
    }

    ll ans = 0;
    vector<ll> M_remain_to_count(M);
    M_remain_to_count[0] = 1;
    for (ll i = 0, sum = 0; i < N; ++i) {
        sum = (sum + A[i]) % M;
        ans += M_remain_to_count[sum % M];
        ++M_remain_to_count[sum];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}