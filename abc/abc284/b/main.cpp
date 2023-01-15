#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int t; cin >> t;
  REP(i,t) {
    int n; cin >> n;
    int ans = 0;
    REP(j,n) {
      int a; cin >> a;
      if (a % 2 == 1) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}