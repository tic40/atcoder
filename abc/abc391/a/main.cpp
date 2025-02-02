#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string d; cin >> d;
  map<char,char> mp = {{'N','S'},{'S','N'},{'W','E'},{'E','W'}};
  for(auto c: d) cout << mp[c];
  return 0;
}