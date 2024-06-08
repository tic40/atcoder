#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  int ans = n;
  REP(i,n) {
    int h; cin >> h;
    m -= h;
    if (m < 0) { ans = i; break; }
  }
  cout << ans << endl;
  return 0;
}