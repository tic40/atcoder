#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

cons int INF = 1001001001;

int main() {
  int h,n;
  cin >> h >> n;
  vector<int> db(h+1, INF);
  dp[0] = 0;
  REP(i,n) {
    int a,b;
    cin >> a >> b;
    REP(j,h) {
      int nj = min(j+a,h);
      dp[nj] = min(dp[nj],dp[j]+b);
    }
  }
  cout << dp[h] << endl;
}
