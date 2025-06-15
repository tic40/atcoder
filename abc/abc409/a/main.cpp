#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string t,a; cin >> n >> t >> a;
  bool ok = false;
  REP(i,n) if (t[i] == 'o' && a[i] == t[i]) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}