#include <stdio.h>
#include <math.h>

double square(double x) {
    return x * x; 
}

/* Actual Riemann sum method 
* The loop essentially divides the interval [a, b] into n 
* subintervals, calculates the x-coordinate of the right 
* endpoint for each subinterval, evaluates the function at 
* each right endpoint, and sums up these evaluations to 
* approximate the integral using the Actual Riemann Sums method.
*/
double actualRiemannSum(double a, double b, int n, int choice, int RChoice) {

    /* This calculates the width of each subinterval (Δx) by dividing 
    * the difference between the upper limit b and lower limit a by the 
    * number of subintervals n. dx represents the step size in the x-axis.
    */
    double dx = (b - a) / n;

    /* This initializes a variable sum to store the running total of 
    * the function evaluations.
    */ 
    double sum = 0.0;
    double Riemm = 0.00;

    // Sets up the chosen function
    double (*calc)(double) = NULL;
    switch (choice) {
        case 1: calc =  square; break;
        case 2: calc =  sin; break;
        case 3: calc =  cos; break;
        case 4: calc =  exp; break;
    }

    /* This modifies the Riemann sum to apply the three types */
    switch (RChoice) {
        // calculates with left endpoints starting from a
        case 1: Riemm = 0; break;
        // calculates with right endpoints starting from a + dx
        case 2: Riemm = dx; break;
        //calculates with midpoints
        case 3: Riemm = dx/2; break;
    }

    //continues until i < n, where n is the number of subintervals specified by the user
    for (int i = 0; i < n; i++) {

        /* calculates the x-coordinate of the right endpoint of the current 
        * subinterval. xi is calculated by adding i * dx to the starting point 
        * a, which moves xi from the left endpoint of the first subinterval to 
        * the right endpoint of the last subinterval.
        */
        double xi = a + Riemm + i * dx;

        /* the function calc(xi) is evaluated at the right endpoint xi of the 
        * current subinterval, and the result is added to the running total sum.
        */
        sum += calc(xi);

        /* The loop repeats this process for each subinterval, evaluating the 
        * function at the right endpoint of each subinterval and accumulating the 
        * results in sum.
        */
    }

    /* After the loop finishes, the total accumulated sum of function 
    * evaluations is multiplied by dx. The multiplication by dx scales the sum to account 
    * for the width of each subinterval, making the result an approximation 
    * of the integral over the given interval [a, b].
    */
    return dx * sum;
}

int main() {
    double a, b;
    int n, choice, RChoice, G_pa = 0;

    printf("\nNumerical Integration Project Team E\nAlejo | Corpuz | Harwani\n");

    do {
    printf("\nEnter the lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter the number of subintervals (int n): ");
    scanf("%d", &n);

    while (n <= 0) {
        printf("\nThe number of subintervals (n) should be greater than 0.\n");
        printf("Enter the number of subintervals (n): ");
        scanf("%d", &n);
    }

    printf("\nChoose the type of Riemann Sum:\n");
    printf("\t1. left\n");
    printf("\t2. right\n");
    printf("\t3. middle\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &RChoice);

    while (RChoice < 1 || RChoice > 3) {
        printf("\nEhh: not a choice\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &RChoice);
    }

    printf("\nChoose a function to integrate:\n");
    printf("\t1. x^2\n");
    printf("\t2. sin(x)\n");
    printf("\t3. cos(x)\n");
    printf("\t4. e^x\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 4) {
        printf("\nEhh: not a choice\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);
    }

    double result = actualRiemannSum(a, b, n, choice, RChoice);

    printf("\nThe approximate integral is: %lf\n", result);
    
    printf("Continue? [1 : Yes] [ 0 : No] : ");
    scanf("%d", &G_pa);
    
    } while (G_pa != 0);

    return 0;
}
