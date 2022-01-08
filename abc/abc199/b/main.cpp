#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  map<int,int> mp;
  REP(i,n) {
    for(int j=a[i]; j<=b[i]; j++) mp[j]++;
  }

  int ans = 0;
  for(auto v: mp)  if(v.second == n) ans++;
  cout << ans << endl;

  return 0;
}