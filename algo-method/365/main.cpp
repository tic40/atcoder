#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector<bool> visited(n);
  visited[0]=true;

  double ans = 0.0;
  // 現在ポジション
  pair<int,int> cur = { x[0], y[0] };

  REP(i,n-1) {
    pair<int,int> nd = { -1, INF }; // {idx, dist}
    REP(j,n) {
      if (visited[j]) continue;
      int dist = pow(x[j]-cur.first,2) + pow(y[j]-cur.second,2);
      if (nd.second > dist) nd = {j, dist};
    }
    // 訪問済
    visited[nd.first] = true;
    // 現在ポジション更新
    cur = { x[nd.first], y[nd.first] };
    // 移動距離を加算
    ans += sqrt( nd.second );
  }

  // 0へ戻る分の移動距離を加算
  ans += sqrt( pow(x[0]-cur.first,2) + pow(y[0]-cur.second,2) );
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}