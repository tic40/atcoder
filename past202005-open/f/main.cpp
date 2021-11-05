#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
int main() {
  cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  string res = "";
  REP(i,n/2) {
    set<char> st1,st2;
    REP(j,n) st1.insert(s[i][j]);
    REP(j,n) st2.insert(s[n-i-1][j]);

    REP(j,26) {
      char c = char('a'+j);
      if (0 < st1.count(c) && 0 < st2.count(c)) {
        res += c;
        break;
      }
    }
  }

  if ((int)res.size() != n/2) {
    cout << -1 << endl;
    return 0;
  }

  string ser = res;
  reverse(ser.begin(),ser.end());
  if (n%2) res += s[n/2][0];

  res += ser;
  cout << res << endl;
  return 0;
}