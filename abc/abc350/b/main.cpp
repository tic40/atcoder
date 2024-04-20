#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> v(n,1);
  REP(i,q) {
    int t; cin >> t; t--;
    v[t] ^= 1;
  }
  cout << accumulate(v.begin(),v.end(),0) << endl;
  return 0;
}