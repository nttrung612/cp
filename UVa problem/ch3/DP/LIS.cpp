#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4+5;

int a[maxN];
int memo[maxN];

int LIS(int i) { // O(n^2) complexity
    if(i == 0) return 1;
    int &ans = memo[i];
    if(ans != -1) return ans;
    ans = 1;
    for(int j=0;j<i;++j) {
        if(a[j] < a[i]) {
            ans = max(ans, LIS(j)+1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(memo, -1, sizeof memo);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    a[n] = 2e9;
    cout << LIS(n)-1 << '\n';

    return 0;
}