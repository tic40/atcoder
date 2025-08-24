#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x,y; cin >> x >> y; x--;
  cout << (x + y) % 12 + 1 << endl;
  return 0;
}