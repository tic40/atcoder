#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> c(5);
  int ans = 0;
  REP(i,4) { int a; cin >> a; a--; c[a]++; }
  REP(i,4) ans += c[i]/2;
  cout << ans << endl;
  return 0;
}