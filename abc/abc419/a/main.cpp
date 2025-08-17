#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  map<string,string> mp = {
    {"red", "SSS"},
    {"blue", "FFF"},
    {"green", "MMM"}
  };
  cout << (mp.count(s) ? mp[s] : "Unknown") << endl;
  return 0;
}