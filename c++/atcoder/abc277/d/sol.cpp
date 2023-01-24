#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get(vector<ll>& root, int x) {
    return x == root[x] ? x : root[x] = get(root, root[x]);
}

void merge(vector<ll>& root, vector<ll>& sum, int x, int y) {
    x = get(root, x);
    y = get(root, y);
    if (x == y) {
        return;
    }

    if (x > y) {
        swap(x, y);
    }
    root[y] = x;
    sum[x] += sum[y];
    sum[y] = 0;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto& Ai : A) {
        cin >> Ai;
    }

    sort(A.begin(), A.end());

    vector<ll> root(N), sum(N);
    for (int i = 0; i < N; ++i) {
        root[i] = i;
        sum[i] = A[i];
    }

    for (int i = 0; i < N; ++i) {
        int cn = A[i];
        int nn = A[(i + 1) % N];
        if (nn == cn or nn == (cn + 1) % M) {
            merge(root, sum, i, (i + 1) % N);
        }
    }

    cout << accumulate(A.begin(), A.end(), 0ll) - *max_element(sum.begin(), sum.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}