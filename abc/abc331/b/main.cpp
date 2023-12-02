#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,s,m,l; cin >> n >> s >> m >> l;

  int ans = 1e9;
  REP(i,100) REP(j,100) REP(k,100) {
    int now = i*6 + j*8 + k*12;
    if (now < n) continue;
    ans = min(ans,s*i + m*j + l*k);
  }
  cout << ans << endl;
  return 0;
}