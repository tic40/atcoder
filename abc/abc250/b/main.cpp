#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,a,b;
  cin >> n >> a >> b;

  REP(i,n) REP(_i,a) {
    REP(j,n) REP(_j,b) {
      bool col = (i%2) ^ (j%2);
      cout << (col ? "#" : ".");
    }
    cout << endl;
  }
}