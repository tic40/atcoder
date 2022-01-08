#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ans = 1, last = 0; // -1, 0, 1

  REP(i,n-1) {
    if (a[i] == a[i+1]) continue;

    int cur = a[i] < a[i+1] ? 1 : -1;
    if (cur == last) continue;

    if (last == 0) {
      last = cur;
    } else {
      last = 0;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}