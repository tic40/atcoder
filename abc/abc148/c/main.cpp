#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  ll a, b;
  cin >> a >> b;

  ll r, x, tmp;
  x = a * b;

  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }

  r = a % b;
  while(r != 0 ) {
    a = b;
    b = r;
    r = a % b;
  }

  cout << x / b << endl;
}