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
    for(char c: s) {
      if (!d[v].to.count(c)) {
        d[v].to[c] = d.size();
        d.push_back(Node());
      }
      v = d[v].to[c];
    }
    d[v].cnt++;
  }

  ll ans;
  int dfs(int v) {
    int res = d[v].cnt;
    for(auto p: d[v].to) {
      res += dfs(p.second);
    }
    if(v) ans += res*ll(res-1) / 2;
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
  Trie t;
  REP(i,n) {
    string s; cin >> s;
    t.add(s);
  }
  ll ans = t.solve();
  cout << ans << endl;
  return 0;
}