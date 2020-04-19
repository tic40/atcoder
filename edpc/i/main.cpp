#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

double dp[3000][3000]; // [i][j] i枚目のコインを投げたときに表がj枚になる確率

int main() {
  int n; cin >> n;
  double p[n];
  REP(i,n) cin >> p[i];

  dp[0][0] = 1.0;

  REP(i,n) {
    for (int j = 0; j <= i; j++) {
      dp[i+1][j+1] += dp[i][j] * p[i];
      dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
    }
  }

  double res = 0.0;
  for (int i = (n+1)/2; i <= n; i++) res += dp[n][i];
  cout << fixed << setprecision(10) << res << endl;
  return 0;
}
