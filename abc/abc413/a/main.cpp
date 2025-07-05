#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  REP(i,n) { int a; cin >> a; m -= a; }
  cout << (m >= 0 ? "Yes" : "No") << endl;
  return 0;
}