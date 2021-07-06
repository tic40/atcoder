#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int a,b;
  cin >> a >> b;
  if (b < a || 6*a < b) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}