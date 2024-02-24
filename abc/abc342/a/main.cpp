#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  map<char,int> mp;
  for(auto c: s) mp[c]++;
  int n = s.size();
  REP(i,n) if (mp[s[i]] == 1) cout << i+1 << endl;
  return 0;
}