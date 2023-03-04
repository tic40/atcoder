#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> v(100);
  REP(_,q) {
    int t,x; cin >> t >> x;
    x--;
    if (t == 1) v[x]++;
    else if (t == 2) v[x]+=2;
    else cout << (v[x] >= 2 ? "Yes" : "No") << endl;
  }
  return 0;
}