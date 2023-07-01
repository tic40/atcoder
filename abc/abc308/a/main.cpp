#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> s(8);
  REP(i,8) cin >> s[i];

  bool ok = true;
  REP(i,7) if (s[i] > s[i+1]) ok = false;
  REP(i,8) if (s[i] < 100 || 675 < s[i]) ok = false;
  REP(i,8) if (s[i] % 25 != 0) ok = false;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}