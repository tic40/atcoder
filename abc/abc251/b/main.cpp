#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,w; cin >> n >> w;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> m(3e6+1);
  REP(i,n) {
    m[a[i]] = 1;
    for(int j = i+1; j < n; j++) {
      m[a[i]+a[j]] = 1;
      for(int k = j+1; k < n; k++) {
        m[a[i]+a[j]+a[k]] = 1;
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= w; i++) ans += m[i];
  cout << ans << endl;
  return 0;
}