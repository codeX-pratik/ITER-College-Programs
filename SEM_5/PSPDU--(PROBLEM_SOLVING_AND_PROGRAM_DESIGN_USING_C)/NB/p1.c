#include <stdio.h>
#include <math.h>

double square_root(double N) {
    double LG = 1.0, NG, diff = 0.005;
    while (1) {
        NG  = 0.5 * (LG + N / LG);
        if (fabs(NG-LG) < diff) break;
        LG = NG;
    }
    return NG;
}

int main() {
    double N, result;
    printf("Enter the value of N : ");
    scanf("%lf", &N);

    result = square_root(N);
    printf("The approx square root of %.2f is %.5f\n", N, result);

    return 0;
}