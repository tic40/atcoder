#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int h,w; cin >> h >> w;
  vector a(h,vector<ll>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];
  ll ans = 0;

  vector b(h,vector<int>(w));
  auto dfs = [&](auto dfs, int now) -> void {
    int i = now/w;
    int j = now%w;
    if (now == h*w-1) {
      ll sum = 0;
      REP(i,h) REP(j,w) if (b[i][j] == 0) sum ^= a[i][j];
      ans = max(ans,sum);
      return;
    }

    dfs(dfs,now+1);
    // 横
    if (b[i][j] == 0 && j+1 < w && b[i][j+1] == 0) {
      b[i][j] = b[i][j+1] = 1;
      dfs(dfs,now+1);
      b[i][j] = b[i][j+1] = 0;
    }
    // 縦
    if (b[i][j] == 0 && i+1 < h && b[i+1][j] == 0) {
      b[i][j] = b[i+1][j] = 1;
      dfs(dfs,now+1);
      b[i][j] = b[i+1][j] = 0;
    }
  };
  dfs(dfs,0);

  cout << ans << endl;
  return 0;
}