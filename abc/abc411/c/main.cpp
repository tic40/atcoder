#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<bool> col(n);
  int ans = 0;
  REP(i,q) {
    int a; cin >> a; a--;
    bool l = a-1 >= 0 && col[a-1];
    bool r = a+1 <= n-1 && col[a+1];
    if (!col[a]) {
      if (l && r) ans--;
      if (!l && !r) ans++;
    } else {
      if (l && r) ans++;
      if (!l && !r) ans--;
    }
    col[a] = !col[a];
    cout << ans << endl;
  }
  return 0;
}