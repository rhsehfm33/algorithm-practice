#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000;

int _ti;

void update_ms(set<int>& s, int& m, int num) {
    m *= num;
    if (s.count(num)) {
        s.erase(num);
    } else {
        s.insert(num);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    set<int> s;
    map<int, int> m1, m2;
    for (auto ai : a) {
        int m = 1;
        for (int i = 2; i * i <= ai; ++i) {
            int b = 0;
            while (ai % i == 0) {
                ai /= i;
                b ^= 1;
            }
            if (b) {
                update_ms(s, m, i);
            }
        }
        if (ai != 1) {
            update_ms(s, m, ai);
        }

        ++m1[m];
        long long prd = 1;
        for (auto& si : s) {
            prd *= si;
            if (prd > MAX) {
                break;
            }
        }
        if (prd <= MAX) {
            ++m2[prd];
        }
    }

    long long ans = 0;
    for (auto [prd, cnt] : m1) {
        ans += 1LL * cnt * m2[prd];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}