#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll n,k; cin >> n >> k;

  REP(i,k) {
    if (n % 200 == 0) n /= 200;
    else n = n*1000 + 200;
  }
  cout << n << endl;
  return 0;
}