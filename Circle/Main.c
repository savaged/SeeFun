#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// TODO: make these user arguments 
#define R 5
#define H 6
#define K 8

typedef enum {
    I = 1, 
    II, 
    III, 
    IV
} quadrantType;

bool output_quadrant(quadrantType q);
double get_x(int theta);
double get_y(int theta);
double transform_x_for_quadrant(double x, quadrantType q);
double transform_y_for_quadrant(double y, quadrantType q);
double shift_x_for_center(double x);
double shift_y_for_center(double y);
bool is_in_domain(int theta);
bool is_in_range(double f);

int main()
{
    for (int i = I; i <= IV; i++)
    {
        int result = output_quadrant((quadrantType)i);

        if (!result)
        {
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}

bool output_quadrant(quadrantType q)
{
    for (int i = 0; i <= 90; i++)
    {
        double x, y;

        x = get_x(i);
        y = get_y(i);
        
        if (is_in_range(x) && is_in_range(y))
        {
            x = transform_x_for_quadrant(x, q);
            y = transform_y_for_quadrant(y, q);
            
            x = shift_x_for_center(x);
            y = shift_y_for_center(y);

            printf("%f, %f\n", x, y);
        }
        else
        {
            printf("%f, %f <- Error: Out of range!\n", x, y);
            return false;
        }
    }
    return true;
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

double transform_x_for_quadrant(double x, quadrantType q)
{
    double value = 0;
    switch (q)
    {
        case I:
        case IV:
            value = x;
            break;
        case II:
        case III:
            value = x * -1;
            break;
    }
    return value;
}

double transform_y_for_quadrant(double y, quadrantType q)
{
    double value = 0;
    switch (q)
    {
        case I:
        case II:
            value = y;
            break;
        case III:
        case IV:
            value = y * -1;
            break;
    }
    return value;
}

double shift_x_for_center(double x)
{
    double value = 0;
    value = x - H;
    return value;
}

double shift_y_for_center(double y)
{
    double value = 0;
    value = y - K;
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

