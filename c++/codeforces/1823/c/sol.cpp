#include <bits/stdc++.h>

using namespace std;

void get_number_of_primes(map<int, int>& prime_to_count, int num) {
    for (int i = 2; i * i <= num; ++i) {
        while (num % i == 0) {
            prime_to_count[i] += 1;
            num /= i;
        }
    }

    if (num != 1) {
        prime_to_count[num] += 1;
    }
}

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    map<int, int> prime_to_count;
    for (auto& ai : a) {
        get_number_of_primes(prime_to_count, ai);
    }

    int ans = 0;
    int rest = 0;
    for (auto& [prime, count] : prime_to_count) {
        ans += count / 2;
        rest += count % 2;
    }
    
    cout << ans + rest / 3 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}