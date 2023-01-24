#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, X, ans = 0;
    cin >> N >> X;
    for (int i = 1; i <= N; ++i) {
        int Pi;
        cin >> Pi;
        if (Pi == X) {
            ans = i;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}