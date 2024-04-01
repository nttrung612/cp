#include <bits/stdc++.h>
using namespace std;

int M, C;
int price[25][25];
bool reachable[2][210];

void solve() {
    cin >> M >> C;
    for(int g=0;g<C;++g) {
        cin >> price[g][0];
        for(int k=1;k<=price[g][0];++k)
            cin >> price[g][k];
    }
    memset(reachable, false, sizeof reachable);
    for(int i=1;i<=price[0][0];++i) if(M - price[0][i] >= 0)
        reachable[0][M-price[0][i]] = true;
    int cur = 1;
    int b; //budget
    for(int g=1;g<C;++g) {
        memset(reachable[cur], false, sizeof reachable[cur]);
        for(b=0;b<M;++b)
            if(reachable[!cur][b])
                for(int k=1;k<=price[g][0];++k) if(b - price[g][k] >= 0)
                    reachable[cur][b - price[g][k]] = true;
        cur = !cur;
    }

    for(b=0;b<=M && !reachable[!cur][b];++b);
    if(b == M+1) cout << "no solution\n";
    else cout << M-b << '\n';
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