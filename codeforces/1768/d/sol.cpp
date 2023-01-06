#include <bits/stdc++.h>

using namespace std;

const int INIT = 1e9;

struct DJS {
    vector<int> par;
    vector<int> cnt;

    DJS(int n) {
        par.resize(n);
        cnt.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }

        if (x > y) {
            swap(x, y);
        }
        par[y] = x;
        cnt[x] += cnt[y];
    }
};

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    DJS djs(n);
    for (int i = 0; i < n; ++i) {
        if (p[i] != i) {
            djs.merge(p[i], i);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int root = djs.find(i);
        if (root == i) {
            sum += djs.cnt[root] - 1;
        }
    }

    int ans = INIT;
    for (int i = 0; i + 1 < n; ++i) {
        int x = djs.find(p[i]);
        int y = djs.find(p[i + 1]);
        if (p[i] == i + 1 or p[i + 1] == i) {
            ans = min(ans, sum - 1);
            break;
        }
        else {
            if (x != y) {
                ans = min(ans, sum + 1);
            }
            else {
                ans = min(ans, sum - 1);
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