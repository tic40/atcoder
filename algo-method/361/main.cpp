#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  int ans = 0;
  sort(a.begin(), a.end());
  REP(i,n) {
    REP(j,m) {
      if (a[i] <= b[j]) {
        b[j]=0;
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}