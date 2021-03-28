#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<int> a(20);

void solve() {
  int ans = 1<<30;

  REP(bit, (1<<n)-1) {
    int now = 0, l = 0;
    REP(i,n) {
      l |= a[i];
      if ((bit>>i)&1) {
        now ^= l;
        l = 0;
      }
    }
    now ^= l;
    ans = min(ans, now);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}