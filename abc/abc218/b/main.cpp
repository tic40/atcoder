#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  REP(i,26) {
    int p; cin >> p;
    cout << char('a'+p-1);
  }
  cout << endl;
  return 0;
}