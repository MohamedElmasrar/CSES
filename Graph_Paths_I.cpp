#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif
 
using namespace std;

const int M = int(1e9) + 7;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
    int n = int(a.size());
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % M;
            }
        }
    }
    return c;
}

void copy(vector<vector<int>> &a, vector<vector<int>> b) {
    int n = int(a.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[i][j];
        }
    }
}

vector<vector<int>> power(vector<vector<int>> a, int k) {
    int n = int(a.size());
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) ans[i][i] = 1;
    while (k) {
        if (k % 2 == 1) {
            copy(ans, multiply(ans, a));
        }
        copy(a, multiply(a, a));
        k /= 2;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a - 1][b - 1] += 1;
    }
    vector ans = power(mat, k);
    cout << ans[0][n - 1] << '\n';
    
    return 0;
}
