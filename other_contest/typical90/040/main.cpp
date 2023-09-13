#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,w; cin >> n >> w;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  // 最小カットを求める
  mf_graph<int> g(n+2);
  REP(i,n) {
    int k; cin >> k;
    REP(j,k) {
      int c; cin >> c;
      c--;
      // 家 i に訪問していないと c に訪れることができないため
      // c -> i へ INF コストの辺を張る
      g.add_edge(c,i,INF);
    }
  }
  REP(i,n) {
    g.add_edge(n,i,a[i]);
    g.add_edge(i,n+1,w);
  }

  // トータル - max_flow = min_flow
  ll ans = accumulate(a.begin(),a.end(),0LL);
  ans -= g.flow(n,n+1);
  cout << ans << endl;
  return 0;
}