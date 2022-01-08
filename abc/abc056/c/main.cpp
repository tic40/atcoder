#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int x,i=0; cin >> x;
  while(x > 0) {
    i++;
    x-=i;
  }
  cout << i << endl;
  return 0;
}