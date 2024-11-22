#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  string t;
  REP(i,n/2) t += '1';
  t += '/';
  REP(i,n/2) t += '2';
  cout << (s == t ? "Yes" : "No") << endl;
  return 0;
}