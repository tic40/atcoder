#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  ll ans = 0;
  int t = 0;
  REP(i,n) {
    // 何周するか
    int r = h[i] / 5;
    ans += r * 3;
    h[i] -= r * 5;
    while(h[i] > 0) {
      t++; ans++;
      h[i] -= t%3==0 ? 3 : 1;
    }
  }
  cout << ans << endl;
  return 0;
}