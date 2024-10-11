#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;


int main() {
  int n,q; cin >> n >> q;
  vector<int> x(n);
  REP(i,n) cin >> x[i];
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<multiset<int>> w(n);
  auto dfs = [&](auto self, int i, int p) -> void {
    w[i].insert(x[i]);
    for(auto v: g[i]) if (v != p) {
      self(self,v,i);
      auto st = w[v];
      w[i].insert(st.begin(),st.end());
    }
    while(w[i].size() > 20) w[i].erase(w[i].begin());
  };

  dfs(dfs,0,-1);
  REP(_,q) {
    int v,k; cin >> v >> k;
    v--; k--;
    auto it = w[v].rbegin();
    advance(it,k);
    cout << *it << endl;
  }

  return 0;
}