#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  int a = (n-1)*2; // 最低限必要な移動回数
  int d = k - a;
  cout << (a <= k && d%2 == 0 ? "Yes" : "No") << endl;

  return 0;
}