#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  ll a,b,k;
  cin>>a>>b>>k;
  if (a > k) { cout << a-k << " " << b;
  } else {
    b = b-(k-a);
    if (b < 0) b = 0;
    cout << 0 << " " << b;
  }
  cout << endl;
}