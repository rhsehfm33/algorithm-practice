#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (st.size() and s[st.back()] < s[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }

    for (int l = 0, r = st.size() - 1; l < r; ++l, --r) {
        swap(s[st[l]], s[st[r]]);
    }

    if (!is_sorted(s.begin(), s.end())) {
        cout << -1 << '\n';
        return;
    }

    int ans = st.size();
    for (int i = st.size() - 1; i >= 0 and s[st[i]] == s[st.back()]; --i) {
        --ans;
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