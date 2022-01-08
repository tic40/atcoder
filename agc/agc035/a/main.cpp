#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a;

bool solve() {
  map<int,int> mp;
  REP(i,n) mp[a[i]]++;

  vector<int> v;
  for(auto x: mp) v.push_back(x.first);
  int sz = v.size();

  if (n % 3 != 0) return mp[0] == n;

  if (sz == 1) return mp[0] == n;
  if (sz == 2) return mp[0] == n/3;
  if (sz == 3) {
    if ( (v[0] ^ v[1] ^ v[2]) != 0 ) return false;
    return mp[v[0]] == n/3 && mp[v[1]] == n/3 && mp[v[2]] == n/3;
  }

  return false;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  cout << (solve() ? "Yes" : "No" ) << endl;
  return 0;
}