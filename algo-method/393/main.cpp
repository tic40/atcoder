#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  int ok = 1000000, ng = 0;
  while(ok-ng > 1) {
    int mid = (ok+ng)/2;
    int cur = a*mid + mid/7*b;
    if (c <= cur) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}