#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i + 2 < N; ++i) {
        if (s.substr(i, 3) == "ABC") {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}