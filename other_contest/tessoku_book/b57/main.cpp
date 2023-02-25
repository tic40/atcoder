#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;

  int logK = 1;
  while ((1LL << logK) <= k) logK++;
  // doubling[k][i] : i番目から 2^k 進んだ町
	vector doubling(logK, vector<int> (300001));
  for(int i = 1; i <= n; i++) {
    doubling[0][i] = i;
    for(char c: to_string(i)) doubling[0][i] -= (c - '0');
  }

  // 前処理 doubling の計算
  REP(i,logK-1) for(int j = 1; j <= n; j++) {
    doubling[i+1][j] = doubling[i][doubling[i][j]];
  }

  for(int i = 1; i <= n; i++) {
    int now = i;
    REP(j,logK) if ((k >> j) & 1) now = doubling[j][now];
    cout << now << endl;
  }
  return 0;
}