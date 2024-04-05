#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(int test) {
    int n; cin >> n;
    int tmp = 1, start = 1, end = 1;
    ll ans = 0, sum = 0;
    for(int i=2;i<=n;++i) {
        int x; cin >> x;
        sum += x;
        if(ans <= sum) {
            if(ans < sum || (ans == sum && i - tmp > end - start)) {
                start = tmp;
                end = i;
            }
            ans = sum;
        }
        if(sum < 0) {
            sum = 0;
            tmp = i;
        }
    }
    if(ans > 0) cout << "The nicest part of route " << test << " is between stops " << start << " and " << end << '\n';
    else cout << "Route " << test << " has no nice parts\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1; cin >> tc;
    for(int test=1;test<=tc;++test) {
        solve(test);
    }
    return 0;
}