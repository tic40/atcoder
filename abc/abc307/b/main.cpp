#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  auto f = [](string s) {
    string t = s;
    reverse(t.begin(),t.end());
    return t == s;
  };

  bool ok = false;
  REP(i,n) REP(j,n) if (i != j && f(s[i]+s[j])) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}