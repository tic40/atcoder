#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { a = max(a,b); }
using P = pair<int,int>;

int main() {
  int n,t; cin >> n >> t;
  vector<P> pa(n);
  REP(i,n) cin >> pa[i].first >> pa[i].second;
  sort(pa.begin(),pa.end());

  vector dp(n+1,vector<int>(t+1));
  REP(i,n) REP(j,t+1) {
    chmax(dp[i+1][j],dp[i][j]);
    if (j < t) chmax(dp[i+1][min(t,j+pa[i].first)], dp[i][j]+pa[i].second);
  }

  cout << *max_element(dp[n].begin(),dp[n].end());
  return 0;
}