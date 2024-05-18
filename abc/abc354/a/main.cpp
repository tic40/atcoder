#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int h; cin >> h;
  int now = 1;
  for(int i = 1;;i++) {
    if (h < now) { cout << i << endl; return 0; }
    now += (1<<i);
  }
  return 0;
}