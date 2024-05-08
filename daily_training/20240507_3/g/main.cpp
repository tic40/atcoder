#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();
template<class T> void chmin(T &a, T b) { a = min(a,b); }

int main() {
  int x,y,z; cin >> x >> y >> z;
  string s; cin >> s;
  int n = s.size();

  vector dp(n+1,vector<ll>(2, LINF));
  dp[0][0] = 0;
  dp[0][1] = z;
  REP(i,n) {
    if (s[i] == 'A') {
      chmin(dp[i+1][0],dp[i][0] + y);
      chmin(dp[i+1][1],dp[i][0] + z + x);
      chmin(dp[i+1][0],dp[i][1] + z + y);
      chmin(dp[i+1][1],dp[i][1] + x);
    } else {
      chmin(dp[i+1][0],dp[i][0] + x);
      chmin(dp[i+1][1],dp[i][0] + z + y);
      chmin(dp[i+1][0],dp[i][1] + z + x);
      chmin(dp[i+1][1],dp[i][1] + y);
    }
  }
  cout << min(dp[n][0],dp[n][1]) << endl;
  return 0;
}