#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    int fc = 0, cc = 0, sc = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] != i and p[i] != n - i + 1) {
            ++cc;
        }
        else if (p[i] != i) {
            ++fc;
        }
        else if (p[i] != n - i + 1) {
            ++sc;
        }
    }

    if (sc + cc < fc) {
        cout << "Second\n";
    }
    else if (fc + cc <= sc) {
        cout << "First\n";
    }
    else {
        cout << "Tie\n";
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