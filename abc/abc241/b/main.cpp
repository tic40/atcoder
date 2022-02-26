#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  map<int,int> mp;
  REP(i,n) mp[a[i]]++;

  REP(i,m) {
    if (mp[b[i]] <= 0) {
      cout << "No" << endl;
      return 0;
    }
    mp[b[i]]--;
  }

  cout << "Yes" << endl;
  return 0;
}