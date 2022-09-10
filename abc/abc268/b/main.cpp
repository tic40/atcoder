#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  cout << (s == t.substr(0,s.size()) ? "Yes" : "No") << endl;

  return 0;
}