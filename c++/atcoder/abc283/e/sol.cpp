#include <bits/stdc++.h>

using namespace std;

const int INF = 2003;

int H, W;
int A[1003][1003];
int dp[1003][4];

bool check(int x, int bs) {
    for (int y = 1; y <= W; ++y) {
        int cur = A[x][y] ^ ((bs >> 1) & 1);
        int up = A[x - 1][y] ^ ((bs >> 2) & 1);
        int right = A[x][y + 1] ^ ((bs >> 1) & 1);
        int left = A[x][y - 1] ^ ((bs >> 1) & 1);
        int down = A[x + 1][y] ^ (bs & 1);
        if (cur != up and cur != right and cur != left and cur != down) {
            return false;
        }
    }

    return true;
}

int dfs(int cx, int bs) {
    if (cx == H + 1) {
        if (check(cx - 1, bs << 1)) {
            return 0;
        }
        else {
            return INF;
        }
    }

    if (dp[cx][bs] != -1) {
        return dp[cx][bs];
    }

    dp[cx][bs] = INF;
    if (check(cx - 1, bs << 1)) {
        dp[cx][bs] = min(dp[cx][bs], dfs(cx + 1, (bs << 1) % 4));
    }
    if (check(cx - 1, (bs << 1) + 1)) {
        dp[cx][bs] = min(dp[cx][bs], 1 + dfs(cx + 1, ((bs << 1) + 1) % 4));
    }
    return dp[cx][bs];
}

void init() {
    for (int x = 0; x < 1003; ++x) {
        for (int y = 0; y < 4; ++y) {
            dp[x][y] = -1;
        }
    }
}

void solve() {
    memset(A, 0, sizeof(A));
    memset(dp, -1, sizeof(dp));
    
    cin >> H >> W;
    for (int x = 1; x <= H; ++x) {
        for (int y = 1; y <= W; ++y) {
            cin >> A[x][y];
        }
    }

    for (int y = 1; y <= W; ++y) {
        A[0][y] = 2;
        A[H + 1][y] = 2;
    }
    for (int x = 1; x <= H; ++x) {
        A[x][0] = 2;
        A[x][W + 1] = 2;
    }

    int ans = min(dfs(2, 0), 1 + dfs(2, 1));
    if (ans >= INF) {
        cout << "-1\n";
    }
    else {
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    init();
    solve();

    return 0;
}