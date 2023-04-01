#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<string> s(8);
  REP(i,8) cin >> s[i];
  REP(i,8) REP(j,8) {
    if (s[i][j] != '*') continue;
    cout << char('a' + j) << 8-i << endl;
    break;
  }
  return 0;
}