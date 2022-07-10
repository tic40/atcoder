#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,m,x,t,d;
  cin >> n >> m >> x >> t >> d;

  cout << (x <= m ? t : (t - d*(x-m))) << endl;
  return 0;
}