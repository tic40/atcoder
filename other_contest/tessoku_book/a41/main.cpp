#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string s; cin >> s;

  bool ok = false;
  REP(i,n-2) {
    if (s[i] == s[i+1] && s[i] == s[i+2]) ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}