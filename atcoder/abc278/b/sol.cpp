#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int h, m;
    cin >> h >> m;
    while (h - h % 10 + m / 10 >= 24 or h % 10 * 10 + m % 10 >= 60) {
        if (++m >= 60) {
            if (++h >= 24) {
                h = 0;
            }
            m = 0;
        }
    }

    cout << h << ' ' << m << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}