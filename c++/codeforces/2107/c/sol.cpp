#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;
const ll INF = 1e17;

ll get_max(vector<ll>& a) {
    ll mx = 0;
    for (ll i = 0, sum = 0; i < a.size(); ++i) {
        sum += a[i];
        if (sum < 0) {
            sum = 0;
        } else if (sum > mx) {
            mx = sum;
        }
    }
    return mx;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (s[i] == '0') {
            a[i] = -INF;
        }
    }

    ll l = -k, h = k, i0 = s.find_first_of('0');
    while (l <= h and i0 != string::npos) {
        ll m = (l + h) / 2;
        a[i0] = m;
        ll mx = get_max(a);
        if (mx < k) {
            l = m + 1;
        } else if (mx > k) {
            h = m - 1;
        } else {
            break;
        }
    }

    if (get_max(a) == k) {
        cout << "Yes\n";
        for (auto& ai : a) {
            cout << ai << ' ';
        }
        cout << '\n';
    } else {
        cout << "No\n";
    }
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