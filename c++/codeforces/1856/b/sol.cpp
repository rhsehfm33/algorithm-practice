#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll sum = 0, c1 = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
        if (ai == 1) {
            ++c1;
        }
    }

    if (n == 1) {
        cout << "No\n";
        return;
    }

    if (sum >= n + c1) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}