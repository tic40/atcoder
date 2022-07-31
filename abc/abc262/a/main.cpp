#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  while(1) {
    if (n % 4 == 2) {
      cout << n << endl;
      return 0;
    }
    n++;
  }
  return 0;
}