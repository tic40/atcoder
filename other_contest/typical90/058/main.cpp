#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e5;

int main() {
  int n; ll k;
  cin >> n >> k;

  int logK = 1;
  while ((1LL << logK) <= k) logK++;

  vector doubling(logK, vector<int>(1e5));
  REP(i,1e5) {
    string s = to_string(i);
    int sum = 0;
    for(char c: s) sum += c-'0';
    doubling[0][i] = (i + sum) % MOD;
  }

  REP(i,logK-1) REP(j,1e5) {
    doubling[i+1][j] = doubling[i][doubling[i][j]];
  }

  int ans = n;
  REP(i,logK) {
    if ((k >> i) & 1) ans = doubling[i][ans];
  }
  cout << ans << endl;
  return 0;
}