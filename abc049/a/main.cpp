#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  char c;
  cin >> c;
  for (auto x : {'a','i','u','e','o'}) {
    if (c == x) { cout << "vowel" << endl; return 0; }
  }
  cout << "consonant" << endl;
}