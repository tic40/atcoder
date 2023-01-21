#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n+1);
  REP(i,n) cin >> a[i+1];

  vector<ll> b(n+1);
  REP(w,n+1) for(int i = 1; i < w; i++) {
    int j = w-i;
    b[w] += a[min(i,j)];
  }

  // dp[i] := 最後の休日がi日目であるときの生産量max
  vector<ll> dp(n+1);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < i; j++) {
      dp[i] = max(dp[i], dp[j]+b[i-j]);
    }
  }

  cout << dp[n] << endl;
  return 0;
}