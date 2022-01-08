#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%s", (n % 3 == 0 ? "YES" : "NO"));
}