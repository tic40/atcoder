#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n-1);
  REP(i,n) cin >> a[i];
  REP(i,n-1) cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  auto f = [&](int x) -> bool {
    auto c = b;
    c.insert(lower_bound(c.begin(),c.end(),x),x);
    REP(i,n) if (a[i] > c[i]) return false;
    return true;
  };

  int ok = 1e9+5, ng = 0;
  while(ok-ng>1) {
    int mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << (ok > 1e9 ? -1 : ok) << endl;
  return 0;
}