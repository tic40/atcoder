#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll ans = 0;
  REP(i,n) ans += abs(a[i] - b[i]);
  cout << ans << endl;
  return 0;
}