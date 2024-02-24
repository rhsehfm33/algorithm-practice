#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        nums[i] = ch - '0';
    }

    stack<ll> ans;
    ll sum = accumulate(nums.begin(), nums.end(), 0);
    for (ll i = n - 1, total = 0; i >= 0 or total > 0; --i) {
        if (i >= 0) {
            total += sum;
            sum -= nums[i];
        }
        ans.push(total % 10);
        total /= 10;
    }

    while (ans.size() > 1 and ans.top() == 0) {
        ans.pop();
    }
    while (ans.size()) {
        cout << ans.top();
        ans.pop();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}