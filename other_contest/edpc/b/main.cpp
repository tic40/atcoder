#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,k; cin >> n >> k;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  vector<int> dp(n,INF);
  dp[0] = 0;
  REP(i,n) {
    for(int j = 1; j <= k; j++) {
      int nj = i+j;
      if (nj >= n) break;
      chmin(dp[nj], dp[i] + abs(h[nj] - h[i]));
    }
  }

  cout << dp[n-1] << endl;
  return 0;
}