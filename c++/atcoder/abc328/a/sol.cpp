#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N, X;
    cin >> N >> X;

    int ans = 0;
    while (N--) {
        int Si;
        cin >> Si;
        ans += Si <= X ? Si : 0;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}