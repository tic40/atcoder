#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> a(n);
  REP(i,n) {
    int t,d; cin >> t >> d;
    a[i] = {d,t};
  }
  sort(a.begin(),a.end());

  const int mx = 1441;
  vector<int> dp(mx);
  REP(i,n) {
    vector<int> p(mx);
    swap(dp,p);
    auto [d,t] = a[i];
    REP(j,mx) {
      if (j - t < 0 || j > d) dp[j] = p[j];
      else dp[j] = max(p[j], p[j-t]+1);
    }
  }

  int ans = *max_element(dp.begin(),dp.end());
  cout << ans << endl;
  return 0;
}