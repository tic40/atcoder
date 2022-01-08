#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  int win = false;
  REP(i,n) {
    int a; cin >> a;
    if (a%2) win = true;
  }

  cout << (win ? "first" : "second") << endl;
  return 0;
}