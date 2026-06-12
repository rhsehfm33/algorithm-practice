#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int _ti;

bool cal(string& a, int i, string& n, string& d, bool big) {
    if (i >= a.size()) {
        return true;
    }
    if (d.find_first_of(a[i]) != string::npos) {
        n += a[i];
        if (cal(a, i + 1, n, d, big)) {
            return true;
        }
        n.pop_back();
    }

    if (big) {
        auto it = lower_bound(d.begin(), d.end(), a[i] + 1);
        if (it == d.end()) {
            return false;
        }
        n += *it;
        n += string(a.size() - n.size(), d.front());
    } else {
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        if (it == d.begin()) {
            return false;
        }
        --it;
        n += *it;
        n += string(a.size() - n.size(), d.back());
    }
    return true;
}

void solve() {
    ll n;
    string a;
    cin >> a >> n;
    string d;
    for (int i = 0, di; i < n; ++i) {
        cin >> di;
        d += (char)('0' + di);
    }

    ll an = stoull(a);
    ll ans = 1e19;
    string n1, n2;
    if (cal(a, 0, n1, d, true)) {
        ans = min(ans, stoull(n1) - an);
    }
    if (d.front() != '0') {
        ans = min(ans, stoull(string(a.size() + 1, d.front())) - an);
    } else if (d.size() > 1) {
        ans = min(ans, stoull(d[1] + string(a.size(), d.front())) - an);
    }

    if (cal(a, 0, n2, d, false)) {
        ans = min(ans, an - stoull(n2));
    }
    if (a.size() > 1) {
        ans = min(ans, an - stoull(string(a.size() - 1, d.back())));
    }
    cout << ans << '\n';
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