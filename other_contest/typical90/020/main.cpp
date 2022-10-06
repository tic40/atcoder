#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b,c; cin >> a >> b >> c;

  // log2(a) < b*log2(c) は、
  // log2(a) < log2(c^b) と置き換えられる
  cout << (a < powl(c,b) ? "Yes" : "No") << endl;
  return 0;
}