#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto& Ai : A) {
        cin >> Ai;
    }
    for (auto& Bi : B) {
        cin >> Bi;
    }
    vector<int> m1, m2;
    for (int i = 0, j = 0; i < N and j < M; ++i) {
        if (A[i] == B[j]) {
            m1.push_back(i);
            ++j;
        }
    }
    for (int i = N - 1, j = M - 1; i >= 0 and j >= 0; --i) {
        if (A[i] == B[j]) {
            m2.push_back(i);
            --j;
        }
    }
    reverse(m2.begin(), m2.end());
    if (m1.size() == M and m2.size() == M and m1 != m2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}