#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define R 5

int output_quadrant();
double get_x(int theta);
double get_y(int theta);
bool is_in_domain(int theta);
bool is_in_range(double f);

int main()
{
    int result = output_quadrant();
    exit(result);
}

int output_quadrant()
{
    for (int i = 0; i <= 90; i++)
    {
        double x, y;

        x = get_x(i);
        y = get_y(i);
        
        if (is_in_range(x) && is_in_range(y))
        {
            printf("%f, %f\n", x, y);
        }
        else
        {
            printf("%f, %f <- Error: Out of range!\n", x, y);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

double get_x(int theta)
{
    if (!is_in_domain(theta)) 
        return (double)-1;

    double sinResultInDegrees, value;

    sinResultInDegrees = sin(theta * (M_PI / 180.0));

    value = sinResultInDegrees * (double)R;
    
    return value;
}

double get_y(int theta)
{
    if (!is_in_domain(theta)) 
        return (double)-1;

    double cosResultInDegrees, value;

    cosResultInDegrees = cos(theta * (M_PI / 180.0));

    value = cosResultInDegrees * (double)R;

    return value;
}

bool is_in_domain(int theta)
{
    bool value;
    value = (theta >= 0 && theta <= 90);
    return value;
}


bool is_in_range(double item)
{
    bool value;
    value = (item >= 0 && item <= (double)R);
    return value;
}

