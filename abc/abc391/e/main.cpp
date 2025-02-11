#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; string s; cin >> n >> s;

  // dp[v][i] := v を i にするコスト
  // 初期値は 1 or 0
  vector dp(s.size(),vector<int>(2,1));
  REP(i,(int)s.size()) dp[i][s[i]-'0'] = 0;

  while((int)dp.size() > 1) {
    vector old((int)dp.size()/3, vector<int>(2,INF));
    swap(dp,old);
    // 3!(1<<3) 通り試す
    for(int l = 0; l < (int)old.size(); l+=3) REP(bit,1<<3) {
      int cost = 0;
      REP(i,3) cost += old[l+i][bit>>i&1];
      int x = __builtin_popcount(bit) >= 2 ? 1 : 0;
      chmin(dp[l/3][x],cost);
    }
  }

  cout << max(dp[0][0],dp[0][1]) << endl;
  return 0;
}
