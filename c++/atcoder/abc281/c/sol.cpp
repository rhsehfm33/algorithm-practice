#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    for (auto& Ai : A) {
        cin >> Ai;
    }

    ll sum = accumulate(A.begin(), A.end(), 0ll);
    T %= sum;
    
    for (int i = 0; i < N; ++i) {
        if (T - A[i] < 0) {
            cout << i + 1 << ' ' << T << '\n';
            return;
        }
        else {
            T -= A[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}