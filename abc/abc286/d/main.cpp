#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,x; cin >> n >> x;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  vector<bool> dp(x+1);
  dp[0] = true;
  REP(i,n) {
    vector<bool> p(x+1);
    swap(dp,p);
    REP(j,x+1) {
      if (!p[j]) continue;
      REP(k,b[i]+1) {
        int nj = j+a[i]*k;
        if (nj > x) break;
        dp[nj] = true;
      }
    }
  }

  cout << (dp[x] ? "Yes" : "No") << endl;
  return 0;
}