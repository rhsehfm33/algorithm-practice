#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 1, j = 0; i <= N; ++i) {
        if (A[j] < i) {
            ++j;
        }
        cout << A[j] - i << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}