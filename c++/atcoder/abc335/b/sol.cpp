#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    for (int i = 0; i <= min(N, 21); ++i) {
        for (int j = 0; j <= min(N, 21); ++j) {
            for (int k = 0; k <= min(N, 21); ++k) {
                if (i + j + k <= N) {
                    cout << i << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}