#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, x;
    cin >> n >> x;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }

    int i = x;
    while (i < n) {
        bool isSuccess = false;
        for (int j = i + i; j <= n; j += i) {
            if (n % j == 0) {
                p[i] = j;
                i = j;
                isSuccess = true;
                break;
            }
        }
        if (isSuccess == false) {
            cout << "-1\n";
            return;
        }
    }
    
    p[n] = 1;
    p[1] = x;
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }
    cout << '\n';
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