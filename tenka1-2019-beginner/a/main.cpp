#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string result = ( (a < c && c < b) || (c < a && b < c) ) ? "Yes" : "No";
  cout << result << endl;
}