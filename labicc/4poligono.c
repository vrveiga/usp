#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

int main(void) {
    int n;
    double l;
    scanf("%d%lf", &n, &l);
    printf("%lf\n", (n*l*l)/(4*tan(PI/n)));
}

// (n*l*l) / (4 * tan(PI/n))