#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;

// dfs解
int dfs() {
  vector<int> dp(100010,-1);

  queue<int> q;
  q.push(0); dp[0]=0;

  auto push = [&](int v, int add){
    int nx = v+add;
    if (dp[nx] == -1) {
      dp[nx] = dp[v]+1;
      q.push(nx);
    }
  };

  while(q.size()) {
    int v = q.front(); q.pop();
    push(v,1);
    for(int p6=6; p6+v<=n; p6*=6) push(v,p6);
    for(int p9=9; p9+v<=n; p9*=9) push(v,p9);
  }

  return dp[n];
}

// dp解
int solve() {
  vector<int> dp(100010,n);
  dp[0] = 0;

  REP(i,n) {
    dp[i+1] = min(dp[i+1], dp[i]+1);
    for(int p6=6; p6+i<=n; p6*=6) {
      dp[i+p6] = min(dp[i+p6], dp[i]+1);
    }
    for(int p9=9; p9+i<=n; p9*=9) {
      dp[i+p9] = min(dp[i+p9], dp[i]+1);
    }
  }

  return dp[n];
}

int main() {
  cin >> n;
  //cout << dfs() << endl;
  cout << solve() << endl;

  return 0;
}