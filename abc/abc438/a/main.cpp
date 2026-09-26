#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int d,f; cin >> d >> f;
  cout << (7 - (d-f) % 7) << endl;
  return 0;
}
