#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) {
            cin >> a[i][j];
            if(i > 0) a[i][j] += a[i-1][j];
        }

    int ans = -1e9;
    for(int l=0;l<n;++l) {
        for(int r=l;r<n;++r) {
            int sum = 0;
            for(int row=0;row<n;++row) {
                if(l > 0) sum += a[row][r] - a[row][l-1];
                else sum += a[row][r];
                if(sum < 0) sum = 0;
                ans = max(ans, sum);
            }
        }
    }

    return 0;
}