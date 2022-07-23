#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> x(n),b(n+1);
  REP(i,n) cin >> x[i];
  REP(i,m) {
    int c,y; cin >> c >> y;
    b[c] = y;
  }

  vector<ll> dp(n+1,-1);
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(n+1,-1);
    swap(dp,p);
    REP(cnt,n) {
      // 裏にする処理
      dp[0] = max(dp[0], p[cnt]);
      // 表にする処理
      if (p[cnt] != -1) {
        dp[cnt+1] = max(dp[cnt+1], p[cnt]+x[i]+b[cnt+1]);
      }
    }
  }

  cout << *max_element(dp.begin(),dp.end()) << endl;
  return 0;
}