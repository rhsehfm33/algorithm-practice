#include <bits/stdc++.h>
 
using namespace std;
 
void solve(int _ti) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << "Second\n";
    } else {
        cout << "First\n";
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