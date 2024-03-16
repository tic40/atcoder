#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll x; cin >> x;
  cout << (x > 0 ? (x+9)/10 : x/10) << endl;
  return 0;
}