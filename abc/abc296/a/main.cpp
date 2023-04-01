#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  char p = s[0];
  bool ok = true;
  for(int i = 1; i < n; i++) {
    if (s[i] == p) ok = false;
    p = s[i];
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}