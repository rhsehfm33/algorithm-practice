#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int mc = 0;
    for (auto& ai : a) {
        if (ai == 0) {
            mc = 1;
            break;
        }
        mc += (ai < 0);
    }

    if (mc % 2) {
        cout << "0\n";
    } else {
        cout << "1\n1 0\n";
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