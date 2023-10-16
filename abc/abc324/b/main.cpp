#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = unsigned long long;

int main() {
  ll n; cin >> n;
  while(n%2 == 0) n/=2;
  while(n%3 == 0) n/=3;
  cout << (n == 1 ? "Yes" : "No") << endl;
  return 0;
}