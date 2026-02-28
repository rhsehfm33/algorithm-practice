#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string x;
    cin >> x;
    int sum = 0;
    vector<int> d;
    for (int i = 0; i < x.size(); ++i) {
        d.push_back(x[i] - (i ? '0' : '1'));
        sum += (x[i] - '0');
    }

    sort(d.begin(), d.end(), greater<int>());
    for (int i = 0; ;++i) {
        if (sum < 10) {
            cout << i << '\n';
            return;
        }
        sum -= d[i];
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