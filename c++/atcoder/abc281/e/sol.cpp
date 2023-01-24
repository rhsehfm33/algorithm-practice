#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll ans = 0;
    ll N, M, K;
    cin >> N >> M >> K;
    multiset<ll> bms, sms;
    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        sms.insert(A[i]);
        ans += A[i];
        if (i <= M - 1) {
            continue;
        }

        if (bms.count(A[i - M])) {
            bms.erase(bms.find(A[i - M]));
        }
        else if (sms.count(A[i - M])) {
            sms.erase(sms.find(A[i - M]));
            ans -= A[i - M];
        }
        while (sms.size() > K) {
            bms.insert(*sms.rbegin());
            ans -= *sms.rbegin();
            sms.erase(prev(sms.end()));
        }
        while (bms.size() and *sms.rbegin() > *bms.begin()) {
            ll sms_num = *sms.rbegin();
            ll bms_num = *bms.begin();
            sms.erase(prev(sms.end()));
            bms.erase(bms.begin());
            ans -= sms_num;
            ans += bms_num;
            sms.insert(bms_num);
            bms.insert(sms_num);
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}