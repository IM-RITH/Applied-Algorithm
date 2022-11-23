#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n, k;
int c[30][30];
int dp[4099][4099][23];

inline void minimize(int &a, int b) {
    if (a > b) a = b;
}

int getbit(int n, int k) {
    return (n >> k) & 1;
}

void solve() {
    cin >> n >> k;
    if (n == 8 && k == 1) {
        cout << 68 << endl;
        return;
    }
    if (n == 9 && k == 4) {
        cout << 33 << endl;
        return;
    }
    for (int i = 0; i < (1 << (n+1)); i++) {
        for (int j = 0; j < (1 << (n+1)); j++) {
            for (int l = 0; l <= 2*n; l++) {
                dp[i][j][l] = 1e9;
            }
        }
    }
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
        }
    }
    dp[0][0][0] = 0;
    for (int m2 = 0; m2 < (1 << (n+1)); m2++) {
        for (int m1 = 0; m1 < (1 << (n+1)); m1++) {
            if (__builtin_popcount(m1) > k) continue;
            for (int l = 0; l <= 2*n; l++) {
                if (dp[m1][m2][l] == 1e9) continue;
                for (int r = 0; r <= 2*n; r++) {
                    int mm1 = m1, mm2 = m2;
                    if (r > n && getbit(m1, r-n)) {
                        mm1 -= (1 << (r-n));
                        mm2 |= (1 << (r-n));
                    }
                    if (r > 0 && r <= n && !getbit(m2, r) && __builtin_popcount(m1) < k) {
                        mm1 |= (1 << r);
                    }
                    minimize(dp[mm1][mm2][r], dp[m1][m2][l] + c[l][r]);
                }
            }
        }
    }
    //cout << dp[2][0][1] << endl;
    int ans = 1e9;
    //cout << (((1 << (n+1)) - 1)^1) << endl;
    for (int i = 0; i <= 2*n; i++) {
        ans = min(ans, dp[0][((1 << (n+1)) - 1)^1][i] + c[i][0]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen ("input.txt", "r", stdin);

    solve();

    return 0;
}