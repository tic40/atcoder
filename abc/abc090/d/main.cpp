#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  if (k == 0) { cout << (ll)n*n << endl; return 0; }

  ll ans = 0;
  for (int b = k+1; b <= n; b++) { // bを決め打つ
    ans += (n/b)*(b-k); // n/b回繰り返す. 1周期にb-k個
    ans += max(0, (n%b) - k + 1); // 最後の分を足す
  }
  cout << ans << endl;

  return 0;
}
