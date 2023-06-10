#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0, j = 0; i < n and count < 4; ++i, ++count) {
            while (j < n and a[j] - a[i] <= mid * 2) {
                ++j;
            }
            i = j - 1;
        }

        if (count < 4) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << high + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}