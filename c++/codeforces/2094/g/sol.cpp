#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll q;
    cin >> q;

    ll f = 0, s = 0;
    array<ll, 2> r = {0, 0};
    list<ll> li;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            ll d;
            if (!f) {
                d = (s - li.back() * li.size());
                li.push_front(li.back());
                li.pop_back();
            } else {
                d = (-s + li.front() * li.size());
                li.push_back(li.front());
                li.pop_front();
            }
            r[0] += d;
            r[1] -= d;
        } else if (c == 2) {
            f ^= 1;
        } else {
            int k;
            cin >> k;
            s += k;
            if (!f) {
                li.push_back(k);
            } else {
                li.push_front(k);
            }
            r[f] += k * li.size();
            r[f ^ 1] += s;
        }
        cout << r[f] << '\n';
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