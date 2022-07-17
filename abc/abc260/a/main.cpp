#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  string s; cin >> s;
  map<char,int> mp;
  for(char c: s) mp[c]++;
  for(auto [k,v]: mp) {
    if (v > 1) continue;
    cout << k << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}