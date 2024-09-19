#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n; cin >> n;
    vector<array<ll, 2>> ab(n), st;
    for (auto& [ai, bi] : ab) {
        cin >> ai >> bi;
    }

    ll sum = 0;
    for (auto [ai, bi] : ab) {
        ll cnt = 0;
        while (st.size() and ai) {
            if (st.back()[1] == bi) {
                sum -= st.back()[0];
                cnt += st.back()[0];
                st.pop_back();
            } else {
                if (st.back()[0] <= ai) {
                    sum -= st.back()[0];
                    cnt += st.back()[0];
                    ai -= st.back()[0];
                    st.pop_back();
                } else {
                    sum -= ai;
                    cnt += ai;
                    st.back()[0] -= ai;
                    ai = 0;
                }
            }
        }
        sum += (cnt + ai);
        cout << sum << ' ';
        st.push_back({cnt + ai, bi});
    }
    cout << '\n';
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