#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,s; cin >> n >> s;
  bool ok = true;
  int now = 0;
  REP(i,n) {
    int t; cin >> t;
    if (t - now > s) ok = false;
    now = t;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}