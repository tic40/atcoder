#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
int main() {
  int n, x, ans = 0, d;
  cin >> n >> x;
  vector<int> l(n);
  REP(i, n) cin >> l[i];
  REP(i, n + 1) {
    if (i == 0) { d = 0; ans++; }
    else { d = d + l[i - 1]; if (d <= x) ans++; }
  }
  cout << ans << endl;
}
