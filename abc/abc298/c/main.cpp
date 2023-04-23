#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector g(n+1,multiset<int>());
  map<int,set<int>> mp;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int i,j; cin >> i >> j;
      g[j].insert(i);
      mp[i].insert(j);
    } else if (t == 2) {
      int i; cin >> i;
      for(auto v: g[i]) cout << v << " ";
      cout << endl;
    } else {
      int i; cin >> i;
      for(auto v: mp[i]) cout << v << " ";
      cout << endl;
    }
  }
  return 0;
}