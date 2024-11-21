#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll _ti;

ll add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

ll sub(ll n1, ll n2) {
    return (n1 - n2 + MOD) % MOD;
}

ll getResult(array<ll, 2> a) {
    ll r = a[0];
    for (ll i = 1, m = 2; i <= a[1]; i <<= 1, m = mul(m, m)) {
        if (a[1] & i) {
            r = mul(r, m);
        }
    }
    return r;
}

bool isRightNotSmaller(array<ll, 2> a1, array<ll, 2> a2) {
    ll sum = a2[0];
    while (sum < a1[0] and a2[1]) {
        sum *= 2;
        --a2[1];
    }
    return sum >= a1[0];
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    stack<array<ll, 2>> s;
    for (auto ai : a) {
        array<ll, 2> ca{0, 0};
        while (ai % 2 == 0) {
            ++ca[1];
            ai /= 2;
        }
        ca[0] = ai;

        while (s.size() and isRightNotSmaller(s.top(), ca)) {
            ans = sub(ans, getResult(s.top()));
            ans = add(ans, s.top()[0]);
            ca[1] += s.top()[1];
            s.pop();
        }
        ans = add(ans, getResult(ca));
        s.push(ca);
        cout << ans << ' ';
    }
    cout << '\n';
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