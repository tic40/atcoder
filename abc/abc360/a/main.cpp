#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int sr,sm;
  int n = s.size();
  REP(i,n) {
    if (s[i] == 'R') sr = i;
    if (s[i] == 'M') sm = i;
  }
  cout << (sr < sm ? "Yes" : "No") << endl;
  return 0;
}