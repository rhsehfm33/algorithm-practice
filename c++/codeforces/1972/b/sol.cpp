#include <bits/stdc++.h>
 
using namespace std;
 
int _ti;
 
void solve() {
    int n, uc = 0;
    cin >> n;
    string s;
    cin >> s;
    for (char ch : s) {
        if (ch == 'U') {
            uc ^= 1;
        }
    }
 
    if (uc) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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