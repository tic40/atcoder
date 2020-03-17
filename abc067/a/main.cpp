#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a,b; cin >> a >> b;
  int ans = 0;
  if ((a+b)%3==0 || a%3==0 || b%3==0) ans = true;
  cout << (ans ? "Possible" : "Impossible") << endl;
  return 0;
}
