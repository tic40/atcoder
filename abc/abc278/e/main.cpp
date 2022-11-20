#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int H,W,n,h,w;
  cin >> H >> W >> n >> h >> w;
  vector a(H,vector<int>(W));
  // 各数字の出現数合計
  vector<int> cnt(n+1), now(n+1);
  REP(i,H) REP(j,W) {
    cin >> a[i][j];
    cnt[a[i][j]]++;
  }
  int tot = 0;
  REP(i,n+1) if (cnt[i] > 0) tot++;

  REP(i,H-h+1) {
    REP(ii,n+1) now[ii] = 0;
    REP(ii,h) REP(jj,w) now[a[i+ii][jj]]++;

    REP(j,W-w+1) {
      int ans = tot;
      if (j != 0) {
        REP(ii,h) {
          now[a[i+ii][j-1]]--;
          now[a[i+ii][j+w-1]]++;
        }
      }
      for(int k = 1; k <= n; k++) if (cnt[k] > 0 && now[k] == cnt[k]) ans--;
      cout << ans << " ";
    }
    cout << endl;
  }
  return 0;
}