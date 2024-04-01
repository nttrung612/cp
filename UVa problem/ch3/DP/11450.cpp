#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int M, C;
int price[25][25];
int memo[210][25];

int dp(int reM, int g) {
    if(reM < 0) return -1e9; //if remaining money < 0 -> not solution -> return INF
    if(g == C) return M-reM; //if buy all garments -> return (total Money - remaining money)
    int &ans = memo[reM][g];
    if(ans != -1) return ans; // if already calculated memo[reM][g]
    for(int i=1;i<=price[g][0];++i) { //search all cases
        ans = max(ans, dp(reM-price[g][i], g+1));
    }
    return ans;
}

void solve() {
    cin >> M >> C;
    for(int i=0;i<C;++i) {
        cin >> price[i][0];
        for(int j=1;j<=price[i][0];++j) cin >> price[i][j];
    }
    memset(memo, -1, sizeof memo);
    if(dp(M, 0) > 0) cout << dp(M,0) << '\n';
    else cout << "no solution\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    cin >> tc;
    while(tc--)
        solve();
    return 0;
}