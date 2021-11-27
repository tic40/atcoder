#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n,m;
int main() {
  cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dsu d(n);
  vector<int> ans;
  ans.push_back(0);
  int curGroup = 0;
  for(int i = n-1; 0 < i; i--) {
    curGroup++;
    for (int v: g[i]) {
      if (v < i) continue;
      if (!d.same(i,v)) curGroup--;
      d.merge(i,v);
    }
    ans.push_back(curGroup);
  }

  reverse(ans.begin(),ans.end());
  for(int v: ans) cout << v << endl;
  return 0;
}