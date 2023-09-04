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

  auto solve1 = [&]() {
    REP(_,q) {
      int k; cin >> k;
      vector<int> v(k);
      vector<bool> used(n);
      REP(j,k) {
        cin >> v[j]; v[j]--;
        used[v[j]] = true;
      }
      auto tree_dp = [&](auto self, int now, int pre) -> void {
        for(int i: g[now]) {
          if (i == pre) continue;
          self(self,i,now);
          used[now] = used[now] || used[i];
        }
      };

      tree_dp(tree_dp,v[0],-1);
      int ans = 0;
      REP(i,n) if (used[i]) ans++;
      ans--; // v[0] の分を引く
      cout << ans << endl;
    }
  };

  // 小課題1解
  solve1();
  return 0;
}