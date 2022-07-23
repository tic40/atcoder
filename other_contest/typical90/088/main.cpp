#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using G = vector<vector<int>>;

int n,q;
vector<int> c(10000);
G g(10000);
vector<G> ans(10000);
vector<int> a,vec;
bool flag = false;

void dfs(int pos, int dep) {
  if (flag) return;
  if (pos == n) {
    ans[dep].push_back(vec);
    if ((int)ans[dep].size() == 2) flag = true;
    return;
  }

  dfs(pos+1, dep);
  if (c[pos] == 0) {
    vec.push_back(pos);
    for(int i: g[pos]) c[i]++;
    dfs(pos+1, dep+a[pos]);
    for(int i: g[pos]) c[i]--;
    vec.pop_back();
  }
  return;
}

int main() {
  cin >> n >> q;
  a.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,q) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
  }

  dfs(0,0);

  REP(i,10000) {
    if (ans[i].size() < 2) continue;

    REP(j,2) {
      cout << ans[i][j].size() << endl;
      for(int v: ans[i][j]) cout << v+1 << " ";
      cout << endl;
    }
    return 0;
  }
  return 0;
}