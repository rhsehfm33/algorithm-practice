#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<array<int, 2>> lr(n);
    for (auto& [l, r] : lr) {
        cin >> l >> r;
    }

    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool success = true;
        int cl = 0, cr = 0;
        for (auto& [l, r] : lr) {
            if (l <= cl) {
                cl = max(cl - mid, l);
            } else {
                cl = min(cl + mid, l);
            }
            if (r <= cr) {
                cr = max(cr - mid, r);
            } else {
                cr = min(cr + mid, r);
            }

            if (cl > r or cr < l) {
                success = false;
                break;
            }
            if (cl < l) {
                cl = l;
            }
            if (cr > r) {
                cr = r;
            }
        }

        if (success) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << high + 1 << '\n';
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