/*
    Author: Yosri Meftah ( zeal1 or zaxxx )
    Competitive Programming Template
*/

#include <bits/stdc++.h>
using namespace std;


struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;
    static const int MAX_BIT = 31; 

public:
    BinaryTrie() {
        root = new TrieNode();
    }

    void insert(int x) {
        TrieNode* node = root;
        for (int b = MAX_BIT; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int maxXorWith(int x) {
        TrieNode* node = root;
        int res = 0;
        for (int b = MAX_BIT; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = 1 - bit;
            if (node->child[want]) {
                res |= (1 << b);
                node = node->child[want];
            } else {
                node = node->child[bit];
            }
        }
        return res;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    if (n == 1) {
        cout << a[0] << '\n';
        return ;
    }

    BinaryTrie trie;
    trie.insert(a[0]);

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, trie.maxXorWith(a[i]));
        trie.insert(a[i]);
    }

    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}