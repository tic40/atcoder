#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll k; cin >> n >> k;
  vector<int> a(n), x(n);
  REP(i,n) { cin >> a[i]; a[i]--; }
  REP(i,n) cin >> x[i];
  int logK = 1;
  while ((1LL << logK) <= k) logK++;

  vector doubling(logK,vector<int>(n));
  REP(i,n) doubling[0][i] = a[i];
  REP(i,logK-1) REP(j,n) {
    doubling[i+1][j] = doubling[i][doubling[i][j]];
  }

  vector<int> ans = x;
  REP(i,logK) {
    if ((k >> i) & 1) {
      vector<int> old(n);
      swap(old,ans);
      REP(j,n) ans[j] = old[doubling[i][j]];
    }
  }

  REP(i,n) cout << ans[i] << " ";
  return 0;
}