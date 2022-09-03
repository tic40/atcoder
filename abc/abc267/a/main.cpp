#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  map<string,int> mp;
  mp["Monday"] = 1;
  mp["Tuesday"] = 2;
  mp["Wednesday"] = 3;
  mp["Thursday"] = 4;
  mp["Friday"] = 5;

  cout << 6 - mp[s] << endl;
  return 0;
}