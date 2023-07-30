#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int ok = 1e9+5, ng = 0;
  while(abs(ok - ng) > 1) {
    int mid = (ok+ng)/2;
    int seller = upper_bound(a.begin(),a.end(),mid) - a.begin();
    int buyer = m - (lower_bound(b.begin(),b.end(),mid) - b.begin());
    if (seller >= buyer) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}