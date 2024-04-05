#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxN = 1e4+5;

vi L, L_id, p;
int a[maxN];

void print_LIS(int i) {
    if(p[i] == -1) {
        cout << a[i];
        return;
    }
    print_LIS(p[i]);
    cout << ' ' << a[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    L.assign(n, 0); L_id.assign(n, 0);
    p.assign(n, -1);
    int k=0, lis_end=0;
    for(int i=0;i<n;++i) {
        int pos = lower_bound(L.begin(), L.begin()+k, a[i]) - L.begin();
        L[pos] = a[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if(pos == k) {
            ++k;
            lis_end = i;
        }
    }
    cout << "LIS length: " << k << '\n';
    cout << "LIS: ";
    print_LIS(lis_end);

    return 0;
}