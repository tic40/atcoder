#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  ll tot = accumulate(a.begin(),a.end(),0LL) ;
  n *= 2;
  a.insert(a.end(),a.begin(),a.end());

  int r = 0, ok = 0;
  ll now = 0;
  REP(l,n) {
    while(r < n) {
      if (now * 10 >= tot) break;
      now += a[r];
      r++;
    }
    ok |= (now*10 == tot);
    now -= a[l];
    if (l == r) r++;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}