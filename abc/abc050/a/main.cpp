#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a,b;
  char o;
  cin >> a >> o >> b;
  cout << (o=='+' ? a+b : a-b) << endl;
}
