#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int gcd(int a, int b) { return b?gcd(b,a%b):a; }

int main() {
  int a,b; cin >> a >> b;
  cout << gcd(a,b);
  return 0;
}