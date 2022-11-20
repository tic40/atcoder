#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  map<int,ll> mp;
  REP(i,n) {
    int a; cin >> a;
    mp[i] = a;
  }

  int base = 0;
  int q; cin >> q;
  REP(_,q) {
    int t; cin >> t;

    if (t == 1) {
      cin >> base;
      mp.clear();
    }

    if (t == 2) {
      int i,x; cin >> i >> x;
      i--;
      mp[i] += x;
    }

    if (t == 3) {
      int i; cin >> i;
      i--;
      cout << mp[i] + base << endl;
    }
  }
  return 0;
}