#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct DJS {
    vector<int> par;

    DJS(int n) {
        for (int i = 0; i < n; ++i) {
            par.push_back(i);
        }
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }

        if (x > y) {
            swap(x, y);
        }
        par[y] = x;

        return true;
    }
};

ll getPowWithM(ll num, ll pow, ll M) {
    ll result = 1;
    for (ll i = 0, cur = num; i <= 30; ++i, cur = (cur * cur) % M) {
        if ((pow >> i) & 1) {
            result = (result * cur) % M;
        }
    }
    return result;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (auto& Ai : A) {
        cin >> Ai;
    }

    vector<array<ll, 3>> vec;
    for (ll i = 0; i < N; ++i) {
        for (ll j = i + 1; j < N; ++j) {
            ll result1 = getPowWithM(A[i], A[j], M);
            ll result2 = getPowWithM(A[j], A[i], M);
            vec.push_back({(result1 + result2) % M, i, j});
        }
    }
    sort(vec.begin(), vec.end(), greater<array<ll, 3>>());

    ll ans = 0;
    DJS djs(N);
    for (auto& [score, x, y] : vec) {
        if (djs.merge(x, y)) {
            ans += score;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}