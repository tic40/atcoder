#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  bool ok = true;
  REP(i,n-2) if (s[i] == "sweet" && s[i] == s[i+1]) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}