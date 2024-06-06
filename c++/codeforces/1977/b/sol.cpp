#include <bits/stdc++.h>
 
using namespace std;
 
int _ti;
 
void solve() {
    int x;
    cin >> x;
    vector<int> ans(31);
    for (int i = 30; i >= 0; --i) {
        if ((x & (1 << i)) == 0) {
            continue;
        }
 
        int j = i;
        while (j and (x & (1 << (j - 1)))) {
            --j;
        }
 
        ans[i + 1] = 1;
        ans[j] = -1;
        i = j;
    }
 
    cout << 31 << '\n';
    for (int i = 0; i < 31; ++i) {
        if (i + 1 < 31 and ans[i] * ans[i + 1] == -1) {
            ans[i] = ans[i + 1];
            ans[i + 1] = 0;
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
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