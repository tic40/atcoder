#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,m,q; cin >> n >> m >> q;
  vector<int> t(q),a(q),b(q),c(q);
  vector<vector<int>> subt(q);
  vector latest(n, pair(-1, 0));
  vector<ll> ans;

  REP(i,q) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> a[i] >> b[i] >> c[i];
      a[i]--;
    } else if (t[i] == 2) {
      cin >> a[i] >> b[i];
      a[i]--;
      latest[a[i]] = pair(i, b[i]);
    } else {
      cin >> a[i] >> b[i];
      a[i]--;
      auto [j,x] = latest[a[i]];
      int id = ans.size();
      ans.push_back(x);
      c[i] = id;
      if (j >= 0) subt[j].push_back(i);
    }
  }

  fenwick_tree<ll> fen(m+1);
  REP(i,q) {
    if (t[i] == 1) {
      fen.add(a[i], c[i]);
      fen.add(b[i], -c[i]);
    } else if(t[i] == 2) {
      for(int j: subt[i]) ans[c[j]] -= fen.sum(0, b[j]);
    } else {
      ans[c[i]] += fen.sum(0,b[i]);
    }
  }

  for(auto x: ans) cout << x << endl;
  return 0;
}