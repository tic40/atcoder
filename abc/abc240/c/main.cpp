#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,x;
  cin >> n >> x;

  vector<bool> dp(10005);
  dp[0] = 1;

  REP(i,n) {
    int a,b; cin >> a >> b;

    vector<bool> p(10005);
    swap(p,dp);
    REP(j, 10001) {
      if (a+j <= 10000 && p[j]) dp[a+j] = 1;
      if (b+j <= 10000 && p[j]) dp[b+j] = 1;
    }
  }

  cout << (dp[x] ? "Yes" : "No") << endl;
  return 0;
}