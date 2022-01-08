#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  vector<string> s(3);
  REP(i,3) cin >> s[i];
  string t;
  cin >> t;

  for(char c: t) cout << s[c - '1'];
  cout << endl;
  return 0;
}