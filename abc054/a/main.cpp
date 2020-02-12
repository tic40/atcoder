#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a, b; cin >> a >> b;
  if (a == 1) a = 14;
  if (b == 1) b = 14;
  if (a > b) cout << "Alice";
  else if (a == b) cout << "Draw";
  else cout << "Bob";
  cout << endl;
}