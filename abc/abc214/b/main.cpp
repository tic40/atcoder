#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int s,t; cin >> s >> t;
  int ans = 0;
  REP(i,101) REP(j,101) REP(k,101) {
    if ( (i+j+k <= s) && i*j*k <= t) ans++;
  }
  cout << ans << endl;
  return 0;
}