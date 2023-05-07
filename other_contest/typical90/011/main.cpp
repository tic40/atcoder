#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<tuple<int,int,int>> t(n);
  REP(i,n) {
    int d,c,s; cin >> d >> c >> s;
    t[i] = { d, c, s };
  }

  sort(t.begin(),t.end());
  // dp[i] := i 日目の終わりに貰っている報酬の最大値
  vector<ll> dp(5001,-1);
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(5001);
    auto [d,c,s] = t[i];
    swap(dp,p);
    REP(j,5001) {
      dp[j] = max(dp[j],p[j]);
      if (p[j] != -1 && j+c <= d) dp[j+c] = max(dp[j+c],p[j] + s);
    }
  }

  cout << *max_element(dp.begin(),dp.end()) << endl;
  return 0;
}