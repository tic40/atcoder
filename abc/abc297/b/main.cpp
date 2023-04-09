#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  const int n = 8;

  map<char,vector<int>> mp;
  REP(i,n) mp[s[i]].push_back(i);

  bool ok = true;
  if ((mp['B'][0] % 2) == (mp['B'][1] % 2) ) {
    ok = false;
  }
  if (mp['R'][0] < mp['K'][0] && mp['K'][0] < mp['R'][1]) {
    //
  } else {
    ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}