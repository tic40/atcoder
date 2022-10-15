#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  map<int,int> mp;
  REP(i,n) { int a; cin >> a; mp[a]++; }

  vector<int> m(n);
  int i = 1;
  for(auto [_,v]: mp) {
    m[mp.size() - i] += v;
    i++;
  }

  REP(i,n) cout << m[i] << endl;
  return 0;
}