#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int rmn = 1e9, ti = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > rmn) {
            ti = i;
            break;
        }
        rmn = min(rmn, a[i]);
    }
    int lmni = min_element(a.begin(), a.end()) - a.begin();
    
    if (lmni < ti) {
        cout << -1 << '\n';
    } else {
        cout << ti + 1 << '\n';
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