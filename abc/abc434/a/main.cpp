#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int w,b; cin >> w >> b;
  w *= 1000;
  cout << w / b + 1 << endl;
  return 0;
}