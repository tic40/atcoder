#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;

  map<int, int> mp;
  int a,b;
  REP(i,m) {
    cin >> a >> b;
    mp[a]++; mp[b]++;
  }

  for(auto v: mp) {
    if (v.second % 2 == 1) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}