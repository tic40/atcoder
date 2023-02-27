#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  vector<int> a(m),b(m);
  REP(i,m) { cin >> a[i] >> b[i]; a[i]--; b[i]--; }

  mf_graph<int> g(n+2);
  int offset = 0;
  REP(i,n) {
    // 効果が正のとき、特急駅にしない場合(始点->i)のコストをp[i]に設定
    if (p[i] >= 0) {
      g.add_edge(n,i,p[i]);
      offset += p[i];
    // 効果が負のとき、特急駅にする場合(i->終点)のコストを-p[i]に設定
    } else {
      g.add_edge(i,n+1,-p[i]);
    }
  }

  REP(i,m) g.add_edge(a[i],b[i],1e9);
  int ans = offset - g.flow(n,n+1);
  cout << ans << endl;
  return 0;
}