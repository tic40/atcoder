#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int w; cin >> w;
  cout << 99 * 3 << endl;
  // 1-99
  for(int i = 1; i <= 99; i++) cout << i << " ";
  // 100-9900
  for(int i = 1; i <= 99; i++) cout << i*100 << " ";
  // 10000-990000
  for(int i = 1; i <= 99; i++) cout << i*10000 << " ";
  cout << endl;

  return 0;
}