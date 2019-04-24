#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  if (a.size() == 1) {
    cout << (a.at(0) == 'a' ? "-1" : "a") << '\n';
  } else {
    for (int i = 0; i < a.size() - 1; i++) cout << 'a';
    cout << '\n';
  }
}