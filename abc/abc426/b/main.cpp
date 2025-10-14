#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  map<char,int> mp;
  for(auto c: s) mp[c]++;
  for(auto [c,cnt]: mp) if (cnt == 1) cout << c << endl;
  return 0;
}