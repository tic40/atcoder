#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  map<char, char> mp = { {'6','9'}, {'9','6'} };

  reverse(s.begin(),s.end());
  REP(i,s.size()) cout << (mp[s[i]] ? mp[s[i]] : s[i]);
  cout << endl;

  return 0;
}