#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct Trie {
  struct Node {
    map<char,int> to;
    int cnt;
    Node(): cnt(0) {}
  };
  vector<Node> d;
  Trie(): d(1) {}

  void add(const string& s) {
    int v = 0;
    for(auto c: s) {
      if (!d[v].to.count(c)) {
        d[v].to[c] = d.size();
        d.push_back(Node());
      }
      v = d[v].to[c];
    }
    d[v].cnt++;
  }

  ll ans = 0;
  int dfs(int v) {
    int res = d[v].cnt;
    for(auto p: d[v].to) res += dfs(p.second);
    if (v > 0) ans += res * ll(res-1) / 2;
    return res;
  }

  ll solve() {
    ans = 0;
    dfs(0);
    return ans;
  }
};

int main() {
  int n; cin >> n;
  Trie trie;
  REP(i,n) {
    string s; cin >> s;
    trie.add(s);
  }
  cout << trie.solve() << endl;
  return 0;
}