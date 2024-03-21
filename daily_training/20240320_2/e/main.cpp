#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  ll x; cin >> x;

  ll tot = accumulate(a.begin(),a.end(),0LL);
  ll r = x / tot;
  ll rem = x % tot;
  ll ans = r * n;
  int i = 0;
  while(rem >= 0) { rem -= a[i]; ans++; i++; }
  cout << ans << endl;
  return 0;
}