#include <bits/stdc++.h>
using namespace std;

int main() {
  double a,b; cin >> a >> b;
  double d = sqrt(a*a+b*b);
  printf("%.10f %.10f\n", a/d, b/d);
  return 0;
}