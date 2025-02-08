#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int _ti;
 
struct Node {
    ll lmn, lmx, rmn, rmx, ans;
    Node() {
        lmn = lmx = rmn = rmx = ans = -2e9;
    }
};
 
void update(vector<Node>& s, ll i, ll p, ll num) {
    s[i].ans = 0;
    s[i].lmn = -num + p;
    s[i].lmx = num + p;
    s[i].rmn = -num - p;
    s[i].rmx = num - p;
    while (i / 2 >= 1) {
        i /= 2;
        Node& ln = s[i * 2];
        Node& rn = s[i * 2 + 1];
        
        s[i].ans = max({ln.ans, rn.ans, ln.lmn + rn.rmx, ln.lmx + rn.rmn});
        s[i].lmn = max(ln.lmn, rn.lmn);
        s[i].lmx = max(ln.lmx, rn.lmx);
        s[i].rmn = max(ln.rmn, rn.rmn);
        s[i].rmx = max(ln.rmx, rn.rmx);
    }
}
 
void solve() {
    ll n, q, ans = 0;
    cin >> n >> q;
    ll sz = 1 << ((int)log2(n - 1) + 2);
    vector<Node> seg(sz + 1);
    for (ll i = 0, ai; i < n; ++i) {
        cin >> ai;
        update(seg, sz / 2 + i, i, ai);
    }
 
    cout << seg[1].ans << '\n';
    while (q--) {
        ll p, x;
        cin >> p >> x;
        --p;
        update(seg, sz / 2 + p, p, x);
        cout << seg[1].ans << '\n';
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