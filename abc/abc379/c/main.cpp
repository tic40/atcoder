#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,ll>;

int main() {
  int n,m; cin >> n >> m;
  vector<P> pa(m);
  REP(i,m) { cin >> pa[i].first; pa[i].first--; }
  REP(i,m) cin >> pa[i].second;
  sort(pa.begin(),pa.end());
  pa.emplace_back(n,0LL); // 番兵追加

  // 0 スタートでなければ不可
  if (pa[0].first != 0) { cout << -1 << endl; return 0;}

  ll ans = 0;
  REP(i,m) {
    auto [l,vol] = pa[i];
    int r = pa[i+1].first;
    int need = r - l - 1;
    ll diff = vol - 1 - need;
    // 次にコマが置かれている位置まで埋められなければ不可
    if (diff < 0) { cout << -1 << endl; return 0; }

    ans += (ll)(need+1)*need/2; // 次にコマが置かれている位置まで埋めるコスト
    ans += diff * (r-l); // 溢れた分を次にコマが置かれている位置へ移動
    pa[i+1].second += diff;
  }
  // 溢れていたら不可
  cout << (pa.back().second == 0 ? ans : -1) << endl;
  return 0;
}