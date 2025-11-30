#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,b; cin >> h >> b;
  cout << max(0,h-b) << endl;
  return 0;
}