#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  vector<char> s(3),t(3);
  REP(i,3) cin >> s[i];
  REP(i,3) cin >> t[i];

  int same = 0;
  REP(i,3) if (s[i] == t[i]) same++;

  bool ok = same == 0 || same == 3;
  cout << ( ok ? "Yes" : "No") << endl;
  return 0;
}