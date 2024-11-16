#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<int> v(10);
  for(auto c: s) v[c-'0']++;
  bool ok = v[1] == 1 && v[2] == 2 && v[3] == 3;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}