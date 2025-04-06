#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a; cin >> a;
  cout << (400 % a != 0 ? -1 : 400/a) << endl;
  return 0;
}
