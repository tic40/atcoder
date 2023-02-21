#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  map<string,int> mp;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      string x; int y;
      cin >> x >> y;
      mp[x] = y;
    } else {
      string x; cin >> x;
      cout << mp[x] << endl;
    }
  }
  return 0;
}