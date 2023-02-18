#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int d,n; cin >> d >> n;
  vector<int> t(d,24);
  REP(i,n) {
    int l,r,h; cin >> l >> r >> h;
    l--; r--;
    for(int j = l; j <= r; j++) t[j] = min(t[j],h);
  }
  int ans = accumulate(t.begin(),t.end(),0);
  cout << ans << endl;

  return 0;
}