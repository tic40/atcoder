#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n,l;
vector<bool> hurdle(100005);
int t1,t2,t3;
// dp[i] = かかる秒数の最小値
vector<int> dp(100005, INF);

void solve() {
  dp[0] = 0;
  REP(i,l) {
    int h = hurdle[i] ? t3 : 0;
    // 行動1
    dp[i+1] = min(dp[i+1], dp[i] + t1 + h);
    // 行動2
    if (l < i+2) {
      dp[l] = min(dp[l], dp[i] + t1/2 + t2/2 + h);
    } else {
      dp[i+2] = min(dp[i+2], dp[i] + t1 + t2 + h);
    }
    // 行動3
    if (l < i+4) {
      int d = l-i;
      int cost = dp[i] + t1/2 + h + t2/2;
      REP(j,d-1) cost += t2;
      dp[l] = min(dp[l], cost);
    } else {
      dp[i+4] = min(dp[i+4], dp[i] + t1 + t2*3 + h);
    }
  }

  cout << dp[l] << endl;
  return;
}

int main() {
  cin >> n >> l;
  REP(i,n) {
    int x; cin >> x;
    hurdle[x] = true;
  }
  cin >> t1 >> t2 >> t3;

  solve();
  return 0;
}