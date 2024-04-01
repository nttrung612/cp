#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<int> se;
    for(int i=0;i<n;++i) {
        int x; cin >> x;
        se.insert(x);
    }
    cout << se.size() << '\n';
}