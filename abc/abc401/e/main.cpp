#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dsu uf(n);
  // 1 - k の頂点を 赤, それ以外の頂点を 黒 としたとき
  //  red[i] := 頂点 i が赤に隣接しているか
  vector<bool> red(n);
  // 赤に隣接している黒の数 = 消す頂点数の最小値
  int ans = 0;
  REP(i,n) {
    for(auto j: g[i]) {
      if (j < i) uf.merge(j,i); // i 未満なら追加可能
      if (j > i && !red[j]) { red[j] = true; ans++; }
    }
    if (red[i]) ans--;
    cout << (uf.size(i) == i+1 ? ans : -1) << endl;
  }
  return 0;
}