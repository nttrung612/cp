#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)2e5+5;
int n,x,a[maxN];
bool vis[maxN];
void solve() {
    cin >> n >> x;
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a,a+n);
    int ans=0, i=0, j=n-1;
    while(i < j) {
        if(a[i] + a[j] > x) {
            --j;
        } else {
            ++ans;
            vis[i] = vis[j]= true;
            ++i; --j;
        }
    }
    for(int k=0;k<n;++k) {
        ans += (vis[k] == false);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    //cin >> tc;
    while(tc--)
        solve();
    return 0;
}