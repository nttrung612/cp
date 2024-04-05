#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxN=  1e3+5;

int n, S;
int V[maxN], W[maxN];
int memo[maxN][maxN];

int dp(int id, int curW) {
    if(id == n || curW == 0) return 0; //if no item or no weight left
    int &ans = memo[id][curW];
    if(ans != -1) return ans;
    if(curW < W[id]) return ans = dp(id+1, curW); //if can't take
    return ans = max(dp(id+1, curW), //not take
                     V[id] + dp(id+1, curW-W[id])); //take
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> S;
    for(int i=0;i<n;++i) cin >> W[i] >> V[i];
    memset(memo, -1, sizeof memo);
    cout << "Max value: ";
    cout << dp(0, S) << '\n';

    return 0;
}