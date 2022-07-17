#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;

  string x = string(n/4, '4');
  if (n%4 > 0) x = char('0' + (n%4)) + x;

  int m = 0;
  for(char c: x) m += c - '0';
  m*=2;
  cout << m << endl << x << endl;

  return 0;
}