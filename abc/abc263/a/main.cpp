#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  map<int,int> mp;
  REP(i,5) {
    int a; cin >> a;
    mp[a]++;
  }
  bool ok = true;
  for(auto [_,v]: mp) if (v != 3 && v != 2) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}