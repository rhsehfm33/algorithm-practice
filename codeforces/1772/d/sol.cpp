#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int lb = 0, ub = 1e9;
    for (int i = 0; i + 1 < a.size(); ++i) {
        int sum = a[i] + a[i + 1];
        if (a[i] < a[i + 1]) {
            ub = min(ub, sum / 2);
        }
        else if (a[i] > a[i + 1]) {
            lb = max(lb, sum / 2 + sum % 2);
        }
        else {
            continue;
        }
    }

    if (lb <= ub) {
        cout << lb << '\n';
    }
    else {
        cout << "-1\n";
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