#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            A[k] = x;
        }
        else {
            int k;
            cin >> k;
            cout << A[k] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}