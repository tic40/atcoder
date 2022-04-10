#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9+5;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int mn = INF;
  REP(i,k) mn = min(mn, a[i]);

  vector<int> dp(k);
  dp[k-1] = a[k-1];
  for(int i = k-2; 0 <= i; i--) dp[i] = min(a[i], dp[i+1]);

  int ans = INF;
  for(int i = k; i < n; i++) {
    if (a[i] <= mn) continue;

    int ok = 0, ng = k;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      if (dp[mid] < a[i]) ok = mid;
      else ng = mid;
    }
    ans = min(ans, i-ok);
  }

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}