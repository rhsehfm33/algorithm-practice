#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

int _ti;

struct gate {
    char c;
    ll a;
};

ll cal(ll a, const gate& g) {
    if (g.c == '+') {
        return g.a;
    } else {
        return a * (g.a - 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<gate>> gates(2, vector<gate>(n));
    for (int i = 0; i < n; ++i) {
        cin >> gates[0][i].c >> gates[0][i].a;
        cin >> gates[1][i].c >> gates[1][i].a;
    }

    vector<int> orders(n);
    for (int i = n - 1, pi = 0; i > 0; --i) {
        if (gates[0][i].c == 'x' or gates[1][i].c == 'x') {
            if (gates[0][i].c == '+') {
                pi = 1;
            } else if (gates[1][i].c == '+') {
                pi = 0;
            } else {
                if (gates[0][i].a > gates[1][i].a) {
                    pi = 0;
                } else if (gates[1][i].a > gates[0][i].a) {
                    pi = 1;
                }
            }
        }
        orders[i - 1] = pi;
    }

    ll a0 = 1, a1 = 1;
    for (ll i = 0; i < n; ++i) {
        ll aa = cal(a0, gates[0][i]) + cal(a1, gates[1][i]);
        if (orders[i] == 0) {
            a0 += aa;
        } else {
            a1 += aa;
        }
    }

    cout << a0 + a1 << '\n';
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