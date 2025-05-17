#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  ll now = 1;
  ll mx = 1;
  REP(i,k) mx*=10;
  mx -= 1;

  REP(i,n) {
    ll a; cin >> a;
    if (now > mx/a) now = 1;
    else now *= a;
  }
  cout << now << endl;
  return 0;
}