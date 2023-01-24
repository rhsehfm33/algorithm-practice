#include <bits/stdc++.h>

using namespace std;

const int MAX = 32000;

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    set<int> used;
    for (auto ai : a) {
        vector<int> cur_primes;

        for (auto prime : primes) {
            if (prime > ai) {
                break;
            }
            if (ai % prime == 0) {
                cur_primes.push_back(prime);
            }
            while (ai % prime == 0) {
                ai /= prime;
            }
        }
        if (ai > 1) {
            cur_primes.push_back(ai);
        }

        for (int cur_prime : cur_primes) {
            if (used.count(cur_prime)) {
                cout << "YES\n";
                return;
            }
            used.insert(cur_prime);
        }
    }

    cout << "NO\n";
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