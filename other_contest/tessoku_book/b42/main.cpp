#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  vector s(4, vector<ll>(n));
  REP(i,n) s[0][i] = a[i]+b[i];
  REP(i,n) s[1][i] = -a[i]+b[i];
  REP(i,n) s[2][i] = a[i]-b[i];
  REP(i,n) s[3][i] = -a[i]-b[i];

  vector<ll> sum(4);
  REP(i,n) REP(j,4) if (s[j][i] > 0) sum[j] += s[j][i];

  ll ans = *max_element(sum.begin(),sum.end());
  cout << ans << endl;

  return 0;
}