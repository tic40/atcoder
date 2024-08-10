#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  unordered_map<int,int> mp;
  int tot = 0;

  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      mp[x]++;
      if (mp[x] == 1) tot++;
    } else if (t == 2) {
      int x; cin >> x;
      mp[x]--;
      if (mp[x] == 0) tot--;
    } else {
      cout << tot << endl;
    }
  }
  return 0;
}