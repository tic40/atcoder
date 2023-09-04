#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q; cin >> q;
  REP(_,q) {
    int k; cin >> k;
    vector<int> v(k);
    REP(j,k) { cin >> v[j]; v[j]--; }
    vector<int> c(n);
    REP(j,k) c[v[j]]++;

    auto tree_dp = [&](auto self, int now, int pre) -> void {
      for(int i: g[now]) {
        if (i == pre) continue;
        self(self,i,now);
        c[now] += c[i];
      }
    };

    tree_dp(tree_dp,v[0],-1);
    int ans = 0;
    REP(i,n) {
      if (i != v[0] && c[i] != 0) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}