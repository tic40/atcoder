#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int h, n, a, sum=0;
  cin >> h >> n;
  REP(i,n) { cin >> a; sum += a; }
  if (h - sum > 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
