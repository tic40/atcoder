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

vector<int> dp(100005, INF);
int main() {
  int n; cin >> n;
  set<int> s; s.insert(1);
  int a=6,b=9;
  while(a <= n) { s.insert(a); a*=6; }
  while(b <= n) { s.insert(b); b*=9; }

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for(auto x: s) {
      if (i-x >= 0) dp[i] = min(dp[i], dp[i-x]+1);
    }
  }
  COUT(dp[n]);
  return 0;
}
