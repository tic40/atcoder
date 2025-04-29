#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

struct Trie {
  vector<map<char,int>> to;
  Trie(): to(1) {}
  int add(const string& s) {
    int v = 0;
    for(char c: s) {
      if (to[v].count(c) == 0) {
        int u = to.size();
        to[v][c] = u;
        to.push_back(map<char,int>());
      }
      v = to[v][c];
    }
    return v;
  }

  int ans = 0;
  vector<bool> ng;
  vector<int> num_y;
  void init() {
    ans = 0;
    int n = to.size();
    ng.resize(n);
    num_y.resize(n);
  }
  void addx(int v) {
    if(ng[v]) return;
    ng[v] = true;
    ans -= num_y[v];
    for(auto [c,u]: to[v]) addx(u);
  }
  void addy(int v) {
    if (ng[v]) return;
    ans++;
    num_y[v]++;
  }
};

int main() {
  int q; cin >> q;
  Trie trie;

  vector<P> qs;
  REP(i,q) {
    int t; string s; cin >> t >> s;
    int v = trie.add(s);
    qs.emplace_back(t,v);
  }
  trie.init();

  for(auto [t,v]: qs) {
    if (t == 1) trie.addx(v);
    if (t == 2) trie.addy(v);
    cout << trie.ans << endl;
  }
  return 0;
}