#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int ans = 0;

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int Di;
        cin >> Di;
        for (int j = 1; j <= Di; ++j) {
            ++ans;
            string s = to_string(i) + to_string(j);
            for (int k = 1; k < s.size(); ++k) {
                if (s[k] != s[0]) {
                    --ans;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}