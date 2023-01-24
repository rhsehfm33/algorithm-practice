#include <bits/stdc++.h>

using namespace std;

const int MAX = 3200;
const int INF = 2e9;

vector<int> primes;

void preset() {
    for (int i = 2; i <= MAX; ++i) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }
}

void solve(int _ti) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
    }

    int ans = INF;
    int diff = y - x;
    for (auto prime : primes) {
        if (prime > diff) {
            break;
        }
        if (diff % prime == 0) {
            ans = min(ans, (prime - (x % prime)) % prime);
        }
        while (diff % prime == 0) {
            diff /= prime;
        }
    }

    if (diff > 1) {
        ans = min(ans, (diff - (x % diff)) % diff);
    }
    if (ans == INF) {
        ans = -1;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}