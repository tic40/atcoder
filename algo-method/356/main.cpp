#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll n; cin >> n;
  cout << (ll)(n - floor(sqrt(n))) << endl;
  return 0;
}