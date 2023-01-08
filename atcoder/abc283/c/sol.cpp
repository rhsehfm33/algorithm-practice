#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string S;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '0' and i + 1 < S.size() and S[i + 1] == '0') {
            ++i;
        }
        ++ans;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}