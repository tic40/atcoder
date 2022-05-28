#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int q; cin >> q;
  map<int,int> mp;

  REP(i,q) {
    int t; cin >> t;

    if(t == 1) {
      int x; cin >> x;
      mp[x]++;
    } else if (t == 2) {
      int x,c; cin >> x >> c;
      mp[x] = max(0, mp[x]-c);
      if (mp[x] == 0) mp.erase(x);
    } else {
      cout << ((--mp.end())->first - mp.begin()->first) << endl;
    }
  }
  return 0;
}