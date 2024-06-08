#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  int cnt = 0;
  REP(i,n) if (isupper(s[i])) cnt++;
  if (cnt > n/2) REP(i,n) cout << char(toupper(s[i]));
  else REP(i,n) cout << char(tolower(s[i]));
  cout << endl;
  return 0;
}