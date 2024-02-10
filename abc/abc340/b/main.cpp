#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  vector<int> v;
  while(q--) {
    int t,x; cin >> t >> x;
    if (t == 1) v.push_back(x);
    else cout << v[v.size() - x] << endl;
  }
  return 0;
}