#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto f = [&](int x) {
    int cur = x;
    int cnt = 0;
    REP(i,x) {
      while(cur < n) {
        if (a[i]*2 <= a[cur]) {
          cnt++; cur++;
          break;
        }
        cur++;
      }
    }
    return cnt;
  };

  int left = 0, right = n;
  int ans = 0;
  while(right-left>1) {
    int mid = (right+left)/2;
    int cnt = f(mid);
    if (ans <= cnt) { right = mid; ans = cnt; }
    else left = mid;
  }

  cout << ans << endl;
  return 0;
}