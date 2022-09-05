#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  dsu d(n);
  REP(i,m) {
    int x,y,_; cin >> x >> y >> _;
    x--; y--;
    d.merge(x,y);
  }

  unordered_set<int> st;
  REP(i,n) st.insert(d.leader(i));
  cout << st.size() << endl;
  return 0;
}