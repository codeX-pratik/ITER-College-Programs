#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c, int *has_real_roots, double *root1, double *root2) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant >= 0) {
        *has_real_roots = 1; 
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else {
        *has_real_roots = 0; 
    }
}

int main() {
    double a, b, c, root1, root2;
    int has_real_roots;

    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    solve_quadratic(a, b, c, &has_real_roots, &root1, &root2);

    if (has_real_roots) {
        printf("Real roots found: \n");
        printf("Root 1: %lf\n", root1);
        printf("Root 2: %lf\n", root2);
    } else {
        printf("No real roots exist.\n");
    }

    return 0;
}
