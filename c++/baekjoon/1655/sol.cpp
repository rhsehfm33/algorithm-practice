#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> bpq;
    priority_queue<int, vector<int>, less<int>> spq;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        
        bpq.push(num);
        if (bpq.size() > (i + 1) / 2) {
            spq.push(bpq.top()); bpq.pop();
        }
        while (bpq.size() and spq.size() and bpq.top() < spq.top()) {
            int temp = bpq.top(); bpq.pop();
            bpq.push(spq.top()); spq.pop();
            spq.push(temp);
        }

        cout << spq.top() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}