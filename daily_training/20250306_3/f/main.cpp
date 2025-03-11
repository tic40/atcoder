#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  ll tot = accumulate(a.begin(),a.end(),0LL);
  vector<int> b(n,tot/n);
  REP(i,tot%n) b[i]++;
  reverse(b.begin(),b.end());
  ll ans = 0;
  REP(i,n) ans += abs(a[i]-b[i]);
  cout << ans/2 << endl;
  return 0;
}
