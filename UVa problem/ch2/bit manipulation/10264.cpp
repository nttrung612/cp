#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<int> vi;
void solve() {
    int n;
    while(cin >> n) {
        int num_e = pow(2, n);
        vi e(num_e);
        for(int i=0;i<num_e;++i) cin >> e[i];
        int ans = 0;
        vi sum(num_e, 0);
        for(int i=0;i<num_e;++i) {
            for(int j=0;j<n;++j) {
                sum[i] += e[i ^ (1<<j)]; // xor voi bit 1 de connect 2 corner (vi 2 corner chung canh se khac nhau 1 bit)
            }
        }
        for(int i=0;i<num_e;++i) {
            for(int j=0;j<n;++j) {
                ans = max(ans, sum[i]+sum[i ^ (1<<j)]); // tim tong cua 1 canh gom 2 corner co sum lon nhat
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}