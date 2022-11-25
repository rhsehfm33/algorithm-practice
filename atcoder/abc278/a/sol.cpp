#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    for (int i = K + 1; i <= N; ++i) {
        cout << a[i] << ' ';
    }
    for (int i = 1; i <= min(N, K); ++i) {
        cout << 0 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}