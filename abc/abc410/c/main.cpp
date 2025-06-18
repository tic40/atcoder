#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  iota(a.begin(),a.end(),1);
  int now = 0;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int p,x; cin >> p >> x; p--;
      a[(p+now)%n] = x;
    }
    if (t == 2) {
      int p; cin >> p; p--;
      cout << a[(p+now)%n] << endl;
    }
    if (t == 3) {
      int k; cin >> k;
      now += k;
      now %= n;
    }
  }
  return 0;
}