#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (auto& Si : S) {
        cin >> Si;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            bool success = true;
            for (int k = 0; k < M; ++k) {
                if (S[i][k] == 'x' and S[j][k] == 'x') {
                    success = false;
                }
            }
            if (success) {
                ++ans;
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