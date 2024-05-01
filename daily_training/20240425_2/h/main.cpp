#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  ll k; cin >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int logK = 1;
  while ((1LL << logK) <= k) logK++;
  vector doubling(logK, vector<ll>(n));

  REP(i,n) doubling[0][i] = a[i];
  REP(i,logK-1) REP(j,n) {
    doubling[i+1][j] = doubling[i][j] + doubling[i][(j + doubling[i][j]) % n];
  }

  ll now = 0;
  REP(i,logK) if ((k >> i) & 1) now += doubling[i][now%n];
  cout << now << endl;
  return 0;
}