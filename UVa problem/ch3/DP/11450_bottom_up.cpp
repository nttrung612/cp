#include <bits/stdc++.h>
using namespace std;

int M, C;
int price[25][25];
bool reachable[25][205];

void solve() {
    cin >> M >> C;
    for(int i=0;i<C;++i) {
        cin >> price[i][0];
        for(int j=1;j<=price[i][0];++j) cin >> price[i][j];
    }
    memset(reachable, false, sizeof reachable);
    for(int k=1;k<=price[0][0];++k) {
        if(M - price[0][k] >= 0) {
            reachable[0][M - price[0][k]] = true;
        }
    }
    for(int g=1;g<C;++g) {
        for(int b=0;b<M;++b) if(reachable[g-1][b])
            for(int k=1;k<=price[g][0];++k) if(b - price[g][k] >= 0)
                reachable[g][b - price[g][k]] = true;
    }
    int ans = -1;
    for(int b=0;b<=M;++b) if(reachable[C-1][b]) {
        ans = M - b; break;
    }
    if(ans == -1) cout << "no solution\n";
    else cout << ans << '\n';
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