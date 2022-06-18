#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ans = 0;
  vector<int> b(4);
  REP(i,n) {
    b[0]++;
    vector<int> pb(4); swap(pb,b);
    REP(j,4) {
      int nb = j + a[i];
      if (nb > 3) ans += pb[j];
      else b[nb] += pb[j];
    }
  }

  cout << ans << endl;
  return 0;
}