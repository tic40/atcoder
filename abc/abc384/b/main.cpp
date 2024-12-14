#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,r; cin >> n >> r;
  REP(i,n) {
    int d,a; cin >> d >> a;
    if (d==1 && r >= 1600 && r <= 2799) r+=a;
    if (d==2 && r >= 1200 && r <= 2399) r+=a;
  }
  cout << r << endl;
  return 0;
}