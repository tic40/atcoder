#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  int q; cin >> q;
  REP(_,q) {
    int b; cin >> b;
    int idx = lower_bound(a.begin(),a.end(),b) - a.begin();
    int ans = min( abs(a[idx]-b), abs(a[max(0,idx-1)]-b) );
    cout << ans << endl;
  }
  return 0;
}