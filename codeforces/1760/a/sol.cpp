#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(), abc.end());
    cout << abc[1] << '\n';
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