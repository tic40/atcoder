#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,c; cin >> n >> c;
  int p = -1e4, ans = 0;
  REP(_,n) {
    int t; cin >> t;
    if (t-p >= c) { ans++; p = t; }
  }
  cout << ans << endl;
  return 0;
}