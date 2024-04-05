#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxN=  1e3+5;

int n;
int coinValue[maxN];
int memo[maxN];

int change(int money) {
    if(money == 0) return 0;
    int &ans = memo[money];
    if(ans != -1) return ans;
    ans = 2e9;
    for(int i=0;i<n;++i) {
        if(coinValue[i] <= money) {
            ans = min(ans, change(money-coinValue[i])+1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;++i) cin >> coinValue[i];
    int money; cin >> money;
    memset(memo, -1, sizeof memo);
    cout << change(money) << '\n';

    return 0;
}