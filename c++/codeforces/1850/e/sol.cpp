#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isSmaller(vector<ll>& s, __int128_t added, __int128_t c) {
    __int128_t sum = 0;
    for (__int128_t si : s) {
        sum += (si + added) * (si + added);
    }

    return sum < c;
}

void solve(int _ti) {
    ll n, c;
    cin >> n >> c;
    vector<ll> s(n);
    for (auto& si : s) {
        cin >> si;
    }

    ll low = 1, high = 1e9;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (isSmaller(s, mid, c)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << (high + 1) / 2 << '\n';
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