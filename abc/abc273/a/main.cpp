#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int f(int x) { return x == 0 ? 1 : x*f(x-1); }
int main() {
  int n; cin >> n;
  cout << f(n) << endl;
  return 0;
}