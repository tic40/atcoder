#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int h,w; cin >> h >> w;
  // コーナーケース
  if (h == 1 || w == 1) cout << h*w << endl;
  else cout << ((h+1)/2) * ((w+1)/2) << endl;
  return 0;
}