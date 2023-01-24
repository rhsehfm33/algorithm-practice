#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll N;
    cin >> N;
    vector<queue<pair<ll, ll>>> A(N + 1);
    for (ll i = 1; i <= N; ++i) {
        ll Ai;
        cin >> Ai;
        A[i].push({0, Ai});
    }

    ll Q;
    cin >> Q;
    for (ll q = 1, allQ = -1, all = 0; q <= Q; ++q) {
        ll t;
        cin >> t;
        if (t == 1) {
            cin >> all;
            allQ = q;
        }
        else if (t == 2) {
            ll i, x;
            cin >> i >> x;
            A[i].push({q, x});
        }
        else {
            ll i;
            cin >> i;
            while (A[i].size() and A[i].front().first < allQ) {
                A[i].pop(); 
            }
            
            ll ans = all;
            if (A[i].size()) {
                ll resultQ = 0;
                ll result = 0;
                while (A[i].size()) {
                    result += A[i].front().second;
                    resultQ = A[i].front().first;
                    A[i].pop();
                }
                A[i].push({resultQ, result});
                ans += result;
            }
            
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}