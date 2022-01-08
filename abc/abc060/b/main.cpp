#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a,b,c; cin >> a >> b >> c;
  for(int i=1; i<=b; i++) {
    if (i*a%b == c) { cout << "YES" << endl; return 0; }
  }
  cout << "NO" << endl;
  return 0;
}