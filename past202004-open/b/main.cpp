#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s; cin >> s;
  vector<int> m(3);
  for(char c: s) m[ c-'a' ]++;
  int mx = 0;
  REP(i,3) if (m[mx] < m[i]) mx = i;
  cout << char('a'+mx) << endl;

  return 0;
}