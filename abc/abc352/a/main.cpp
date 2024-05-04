#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x,y,z; cin >> n >> x >> y >> z;
  if (x > y) swap(x,y);
  cout << (x <= z && z <= y ? "Yes" : "No") << endl;
  return 0;
}