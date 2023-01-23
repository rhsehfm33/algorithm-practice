#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 300005;
 
vector<int> get_primes(int num) {
    vector<int> result;
    int cur_num = num;
    for (int i = 2; i * i <= num and cur_num > 1; ++i) {
        if (cur_num % i == 0) {
            result.push_back(i);
        }
        while (cur_num % i == 0) {
            cur_num /= i;
        }
    }
    if (cur_num > 1) {
        result.push_back(cur_num);
    }
 
    return result;
}
 
void solve() {
    vector<vector<int>> ai2v(MAX);
 
    int n, s, t;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ai2v[a[i]].push_back(i);
    }
    cin >> s >> t;
    --s;
    --t;

    if (s == t) {
        cout << "1\n" << s + 1 << '\n';
        return;
    }
 
    bool is_success = false;
    vector<bool> vis(MAX, false);
    vector<int> from(n, -1);
    from[s] = s;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (u == t) {
            is_success = true;
            break;
        }
 
        vector<int> primes = get_primes(a[u]);
        for (int prime : primes) {
            if (vis[prime]) {
                continue;
            }
            vis[prime] = true;

            for (int i = prime; i < MAX; i += prime) {
                for (auto& v : ai2v[i]) {
                    if (from[v] == -1) {
                        from[v] = u;
                        q.push(v);
                    }
                }
            }
        }
    }
 
    if (is_success == false) {
        cout << "-1\n";
        return;
    }
 
    vector<int> ans = {t};
    while (from[t] != t) {
        ans.push_back(from[t]);
        t = from[t];
    }
 
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    solve();
 
    return 0;
}
