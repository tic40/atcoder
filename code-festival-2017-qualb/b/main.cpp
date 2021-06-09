#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n;
  map<int, int> mp;
  REP(i,n) {
    int d; cin >> d;
    mp[d]++;
  }

  cin >> m;
  REP(i,m) {
    int t; cin >> t;
    mp[t]--;
    if (mp[t] < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}