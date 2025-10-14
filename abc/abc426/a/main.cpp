#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string x,y; cin >> x >> y;
  map<string,int> mp = {
    { "Ocelot", 1 },
    { "Serval", 2 },
    { "Lynx", 3 }
  };
  cout << (mp[y] <= mp[x] ? "Yes" : "No") << endl;
  return 0;
}