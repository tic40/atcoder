#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int x;
  cin >> x;
  vector<int> a(4);
  REP(i,4) cin >> a[i];
  vector<int> b = { 50, 10, 5, 1 };

  int ans = 0;
  REP(i,4) {
    REP(j,a[i]) {
      if (x - b[i] < 0) continue;
      x -= b[i];
      ans++;
      if (x == 0) {
        cout << ans << endl;
        return 0;
      }
    }
  }

  return 0;
}