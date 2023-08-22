#include <bits/stdc++.h>

using namespace std;

bool go(vector<int>& a, int k, int idx, int target) {
    for (int i = idx; i < a.size(); ++i, --target) {
        if (a[i] >= target) {
            return true;
        }
        if (target - a[i] > k) {
            return false;
        }
        k -= (target - a[i]);
    }

    return false;
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = *max_element(a.begin(), a.end());
    for (int i = 0; i + 1 < a.size(); ++i) {
        int low = 0;
        int high = k;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (go(a, k, i, a[i] + mid)) {
                ans = max(ans, a[i] + mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    cout << ans << '\n';
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