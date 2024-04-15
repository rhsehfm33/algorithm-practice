#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    for (int i = 1, num = 1 % n; ; ++i) {
        if (num == 0) {
            cout << i << '\n';
            return;
        }
        num = (num * 10 + 1) % n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while (std::cin >> n) {
        solve(n);
    }
}