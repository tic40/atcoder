#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string t,u; cin >> t >> u;
  int n = t.size();
  int nu = u.size();
  REP(i,n-nu+1) {
    bool ok = true;
    REP(j,nu) {
      if (t[i+j] != '?' && t[i+j] != u[j]) ok = false;
    }
    if (ok) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}