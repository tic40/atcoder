#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  ll sum = accumulate(a.begin(),a.end(),0LL);
  if (sum % 10) { cout << "No" << endl; return 0; }
  ll t = sum/10;

  int r = 0;
  ll now = 0;
  bool ok = false;
  REP(l,n) {
    while(r < n*2) {
      if (t <= now) break;
      now += a[r%n];
      r++;
    }
    if (t == now) { ok = true; break; }
    if (r == l) r++;
    now -= a[l];
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}