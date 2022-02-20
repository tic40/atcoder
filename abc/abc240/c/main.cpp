#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> a(n),b(n);

  REP(i,n) cin >> a[i] >> b[i];
  vector<int> dp(10005);

  dp[0] = 1;
  REP(i,n) {
    vector<int> p(10005);
    swap(dp,p);
    REP(j,10001) {
      if (j + a[i] <= 10000 && p[j] ) {
        dp[j + a[i]] = 1;
      }
      if (j + b[i] <= 10000 && p[j] ) {
        dp[j + b[i]] = 1;
      }
    }
  }

  cout << (dp[x] ? "Yes" : "No") << endl;
  return 0;
}