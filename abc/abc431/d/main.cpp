#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector<tuple<int,int,int>> tp;
  int totw = 0;
  REP(i,n) {
    int w,h,b; cin >> w >> h >> b;
    tp.emplace_back(w,h,b);
    totw += w;
  }

  int k = totw/2;
  vector dp(n+1,vector<ll>(k+1,-1));
  dp[0][0] = 0;
  REP(i,n) {
    auto [w,h,b] = tp[i];
    REP(j,k+1) if (dp[i][j] != -1) {
      if (j+w <= k) chmax(dp[i+1][j+w], dp[i][j] + h);
      chmax(dp[i+1][j], dp[i][j] + b);
    }
  }

  cout << *max_element(dp[n].begin(),dp[n].end()) << endl;
  return 0;
}