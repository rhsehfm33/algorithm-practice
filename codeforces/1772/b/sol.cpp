#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    vector<vector<int>> a(2, vector<int>(2));
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];

    for (int i = 0; i < 4; ++i) {
        int first = a[0][0];
        a[0][0] = a[1][0];
        a[1][0] = a[1][1];
        a[1][1] = a[0][1];
        a[0][1] = first;
        
        if (a[0][0] < a[0][1] and
        a[1][0] < a[1][1] and
        a[0][0] < a[1][0] and
        a[0][1] < a[1][1]) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
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