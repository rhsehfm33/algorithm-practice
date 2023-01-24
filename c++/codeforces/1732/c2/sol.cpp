#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isLeftBetter(ll value1, ll value2, ll len1, ll len2) {
    return value1 > value2 or (value1 == value2 and len1 < len2);
}

void solve(int _ti) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> rsum(n + 1), rxor(n + 1), idxs;
    for (int i = 1; i <= n; ++i) {
        rsum[i] = a[i] + rsum[i - 1];
        rxor[i] = a[i] ^ rxor[i - 1];
        if (a[i]) {
            idxs.push_back(i);
        }
    }

    while (q--) {
        int Li, Ri;
        cin >> Li >> Ri;
        int l1 = lower_bound(idxs.begin(), idxs.end(), Li) - idxs.begin();
        int r1 = (lower_bound(idxs.begin(), idxs.end(), Ri + 1) - idxs.begin()) - 1;
        if ((l1 >= idxs.size() or idxs[l1] >= Ri) or (r1 < 0 or idxs[r1] <= Li)) {
            cout << Li << ' ' << Li << '\n';
            continue;
        }

        ll mx = -1, la = 0, ra = 1234560;
        for (int i = 0; i <= 30 and i < r1 - l1 + 1; ++i) {
            for (int j = r1 - i, diff = r1 - l1 - i; j <= r1; ++j) {
                ll csum = rsum[idxs[j]] - rsum[idxs[j - diff] - 1];
                ll cxor = rxor[idxs[j]] ^ rxor[idxs[j - diff] - 1];
                if (isLeftBetter(csum - cxor, mx, idxs[j] - idxs[j - diff], ra - la)) {
                    mx = csum - cxor;
                    ra = idxs[j];
                    la = idxs[j - diff];
                }
            }
        }

        cout << la << ' ' << ra << '\n';
    }
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