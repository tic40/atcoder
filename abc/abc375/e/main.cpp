#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];
  int tot = accumulate(b.begin(),b.end(),0);

  if (tot % 3 != 0) { cout << -1 << endl; return 0; }
  int t = tot/3;

  vector dp(t+1,vector<int>(t+1,INF));
  dp[0][0]=0;
  REP(i,n) {
    vector p(t+1,vector<int>(t+1,INF));
    swap(dp,p);
    REP(s1,t+1) REP(s2,t+1) if(p[s1][s2] != INF) {
      if (s1+b[i] <= t) chmin(dp[s1+b[i]][s2], p[s1][s2] + (a[i]!=1));
      if (s2+b[i] <= t) chmin(dp[s1][s2+b[i]], p[s1][s2] + (a[i]!=2));
      chmin(dp[s1][s2],p[s1][s2] + (a[i]!=3));
    }
  }

  cout << (dp[t][t] == INF ? -1 : dp[t][t]) << endl;
  return 0;
}