#include <bits/stdc++.h>
 
using namespace std;
 
int _ti;
 
vector<int> ps;
 
void preset() {
    for (int i = 2; i <= (1 << 6); ++i) {
        int sum = 0;
        for (int j = 0; j <= 6; ++j) {
            if (i & (1 << j)) {
                sum += pow(10, j);
            }
        }
        ps.push_back(sum);
    }
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < ps.size(); ++i) {
        int cn = n;
        for (int j = i; j < ps.size(); ++j) {
            while (cn % ps[j] == 0) {
                cn /= ps[j];
            }
        }
        if (cn == 1) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();
 
    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }
 
    return 0;
}