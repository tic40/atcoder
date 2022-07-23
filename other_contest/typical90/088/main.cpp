#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using G = vector<vector<int>>;

int n,q;
vector<int> a(100),c(10000),vec;
G g(10000);
vector<G> ans(10000);
bool flag = false;

void dfs(int pos, int sum) {
  if (flag) return;
  if (pos == n) {
    ans[sum].push_back(vec);
    // 答えが見つかったらdfsを終了させる
    if ((int)ans[sum].size() == 2) flag = true;
    return;
  }

  // 選ばない
  dfs(pos+1, sum);
  // 選ぶ
  if (c[pos] == 0) {
    vec.push_back(pos);
    for(int i: g[pos]) c[i]++;
    dfs(pos+1, sum+a[pos]);
    for(int i: g[pos]) c[i]--;
    vec.pop_back();
  }
  return;
}

int main() {
  cin >> n >> q;
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