#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  map<int,ll> mp;
  ll now = 0;
  REP(i,n) {
    int a,b; cin >> a >> b;
    now += b; mp[a+1] += b;
  }
  mp[1] = 0;
  for(auto [day,cnt]: mp) {
    now -= cnt;
    if (now <= k) { cout << day << endl; break; }
  }
  return 0;
}
