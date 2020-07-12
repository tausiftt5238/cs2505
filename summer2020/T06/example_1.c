#include <stdio.h>

double average(double a, double b);
int main(void) {
  double x, y;

  printf("Enter two numbers: ");
  scanf("%lf%lf", &x, &y);
  printf("Average of %g and %g: %g\n", x, y, average(x, y));
  return 0;
}

double average(double a, double b) {
  return (a + b) / 2;
}
