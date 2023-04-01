#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  ll tot = accumulate(a.begin(),a.end(),0LL);
  a.insert(a.end(),a.begin(),a.end());
  n *= 2;

  if (tot % 10) { cout << "No" << endl; return 0; }

  ll t = tot / 10;
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];
  bool ok = false;

  int r = 0;
  ll now = 0;
  REP(l,n) {
    while(r < n) {
      if (t <= now) break;
      now += a[r];
      r++;
    }
    if (t == now) { ok = true; break; }
    if (r == l) r++;
    now -= a[l];
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}