#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = 1e9;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m), cb(m);

  REP(i,m) {
    int b; cin >> a[i] >> b;
    REP(j,b) {
      int c; cin >> c;
      c--;
      cb[i] |= 1<<c;
    }
  }

  vector<int> dp(1<<n,INF);
  dp[0] = 0;
  REP(i,m) {
    vector<int> p(1<<n,INF);
    swap(dp,p);

    REP(bit, 1<<n) {
      dp[bit] = min(dp[bit],p[bit]);
      dp[bit | cb[i]] = min(dp[bit | cb[i]], p[bit]+a[i]);
    }
  }

  cout << (dp[(1<<n)-1] == INF ? -1 : dp[(1<<n)-1]) << endl;
  return 0;
}