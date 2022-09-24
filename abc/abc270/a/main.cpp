#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int a,b; cin >> a >> b;
  int ans = 0;
  REP(i,3) {
    bool ok = false;
    if (a >> i & 1) ok = true;
    if (b >> i & 1) ok = true;
    if (ok) ans += 1 << i;
  }

  cout << ans << endl;
  return 0;
}