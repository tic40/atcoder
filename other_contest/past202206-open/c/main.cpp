#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; int m;
  cin >> n >> m;

  if (n == 1) {
    string s1(m,'o');
    cout << s1 << endl;
    return 0;
  }

  ll x = 1; int k = 0;
  while(x <= 1e9) { x *= n; k++; }

  string s1(min(m,k-1),'o');
  string s2(m-s1.size(),'x');
  cout << s1 << s2 << endl;
  return 0;
}