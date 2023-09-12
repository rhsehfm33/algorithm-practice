#include <bits/stdc++.h>

using namespace std;

void solve() {
    int ans = 2e9;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int Ai;
        cin >> Ai;
        ans = min(ans, abs(Ai));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}