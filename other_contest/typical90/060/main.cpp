#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = numeric_limits<int>::max();

vector<int> lis(const vector<int> &a) {
  int n = a.size();
  vector<int> dp(n,INF), res(n);
  REP(i,n) {
    int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    dp[pos] = a[i];
    res[i] = pos+1;
  }

  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto lis1 = lis(a);
  reverse(a.begin(),a.end());
  auto lis2 = lis(a); // a を reverse して lis
  reverse(lis2.begin(),lis2.end());

  int ans = 0;
  REP(i,n) ans = max(ans, lis1[i] + lis2[i]-1);
  cout << ans << endl;
  return 0;
}