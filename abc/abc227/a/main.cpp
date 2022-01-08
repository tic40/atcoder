#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,k,a;
  cin >> n >> k >> a;
  a += k-1;
  a %= n;
  cout << (a == 0 ? n : a) << endl;
  return 0;
}