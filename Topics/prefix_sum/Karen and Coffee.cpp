#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n , k , q;
    cin >> n >> k >> q;
    vector<int> pref(200001, 0);
    for (int i = 0; i < n; i++) {
        int l , r;
        cin >> l >> r;
        pref[l]++;
        pref[r + 1]--;
    }
    for (int i = 1; i <= 200000; i++) {
        pref[i] += pref[i - 1];
    }
    for (int i = 1; i <= 200000; i++) {
        if(pref[i] >= k) {
            pref[i] = 1;
        } else {
            pref[i] = 0;
        }
    }
    for (int i = 1; i <= 200000; i++) {
        pref[i] += pref[i - 1];
    }
    while(q--) {
        int a , b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}