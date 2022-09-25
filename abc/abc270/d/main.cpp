#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = numeric_limits<int>::max();

int n,k;
vector<int> a(100);
// memo[i][j] := 山の残りの石の数がi、手番がj(0:高橋,1:青木)のときの高橋が取り除ける最大の石の数
vector memo(10001, vector<int>(2));

int f(int x, int t) {
  if (abs(memo[x][t]) != INF) return memo[x][t];
  if (x == 0) return memo[x][t] = 0;

  REP(i,k) {
    if (x - a[i] < 0) break;

    if (t == 0) {
      memo[x][t] = max(memo[x][t], a[i] + f(x-a[i],1));
    } else {
      memo[x][t] = min(memo[x][t], f(x-a[i],0));
    }
  }

  return memo[x][t];
}

int main() {
  cin >> n >> k;
  REP(i,n) cin >> a[i];
  REP(i,n+1) {
    memo[i][0] = -INF;
    memo[i][1] = INF;
  }

  cout << f(n,0) << endl;
  return 0;
}