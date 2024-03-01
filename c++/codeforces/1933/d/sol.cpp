#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int mn = *min_element(a.begin(), a.end()), mnc = 0, mul = 1;
    for (auto& ai : a) {
        if (ai == mn) {
            ++mnc;
        }
        if (ai % mn) {
            mul = 0;
        }
    }
    if (mul and mnc > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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