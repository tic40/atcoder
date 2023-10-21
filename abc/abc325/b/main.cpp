#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> w(n),x(n);
  REP(i,n) cin >> w[i] >> x[i];
  int ans = 0;
  for(int t = 0; t <= 23; t++) {
    int sum = 0;
    REP(i,n) {
      int now = (t + x[i]) % 24;
      if (now >= 9 && now <= 17) sum += w[i];
    }
    ans = max(ans,sum);
  }
  cout << ans << endl;
  return 0;
}