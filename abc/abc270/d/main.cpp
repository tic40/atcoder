#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int n,k;
vector<int> a(100);
vector memo(10001, vector<int>(2));

int f(int x, int t) {
  if (abs(memo[x][t]) != INF) return memo[x][t];
  if (x == 0) return memo[x][t] = 0;

  REP(i,k) {
    if (x - a[i] < 0) break;
    if (t == 1) {
      memo[x][t] = max(memo[x][t], a[i] + f(x-a[i], 0));
    } else {
      memo[x][t] = min(memo[x][t], f(x-a[i], 1));
    }
  }

  return memo[x][t];
}

int main() {
  cin >> n >> k;
  REP(i,k) cin >> a[i];

  REP(i,n+1) {
    memo[i][0] = INF;
    memo[i][1] = -INF;
  }
  cout << f(n,1) << endl;
  return 0;
}