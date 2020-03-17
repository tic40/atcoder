#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a[3]; REP(i,3) cin>>a[i];
  sort(a,a+3);
  cout << a[0]+a[1] << endl;
  return 0;
}
