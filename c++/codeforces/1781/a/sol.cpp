#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int w, d, h, a, b, f, g;
    cin >> w >> d >> h >> a >> b >> f >> g;

    int result1 = h + (a + f) + abs(g - b);
    int result2 = h + (2 * w - a - f) + abs(g - b);
    int result3 = h + (g + b) + abs(f - a);
    int result4 = h + (2 * d - g - b) + abs(f - a);
    cout << min(min(result1, result2), min(result3, result4)) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}