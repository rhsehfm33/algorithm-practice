#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    int low = 0, high = n - 1;
    while (low <= high) {
        bool isSuccess = true;
        int mid = (low + high) / 2;
        for (int l = 0, r = mid; l < r; ++l, --r) {
            if (a[l] + a[r] > m) {
                isSuccess = false;
                break;
            }
        }

        if (isSuccess) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    ll ans = accumulate(a.begin(), a.end(), 0ll) + (n - (low - 1));
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}