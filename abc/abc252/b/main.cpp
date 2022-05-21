#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n),b(k);
  int mx = -1;
  REP(i,n) { cin >> a[i]; mx = max(mx,a[i]); }
  REP(i,k) { cin >> b[i]; b[i]--; }

  bool yes = false;
  REP(i,n) {
    if (mx != a[i]) continue;
    REP(j,k) yes |= (i == b[j]);
  }

  cout << (yes ? "Yes" : "No") << endl;
  return 0;
}