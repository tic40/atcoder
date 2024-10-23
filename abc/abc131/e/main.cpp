#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,k; cin >> n >> k;
  int mx = (n-1)*(n-2)/2; // 最大数
  if (mx < k) { cout << -1 << endl; return 0; }

  vector<P> ans, edges;
  // 最大ケースのスターグラフを作る.(頂点 n-1 を中心とする)
  REP(i,n-1) ans.emplace_back(i,n-1);
  // 最大ケースから最短距離2のペアが k 個になるようにペアを減らしていく
  REP(i,n-1) REP(j,i) edges.emplace_back(i,j);
  REP(i,mx-k) ans.push_back(edges[i]);
  cout << ans.size() << endl;
  for(auto [u,v]: ans) cout << u+1 << " " << v+1 << endl;
  return 0;
}