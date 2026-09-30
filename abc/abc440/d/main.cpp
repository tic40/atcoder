#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  REP(_,q) {
    int x,y; cin >> x >> y;
    ll ok = 0, ng = 1e10;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      auto itx = lower_bound(a.begin(),a.end(),x);
      auto itmid = lower_bound(a.begin(),a.end(),mid);

      int cnta = itmid - itx;
      if (mid - x + 1 - cnta > y) ng = mid;
      else ok = mid;
    }
    cout << ok << endl;
  }
  return 0;
}
