#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int r;
int h;
int k;

typedef enum {
    I = 1, 
    II, 
    III, 
    IV
} quadrantType;

bool process_args(int argc, char *argv[]);
int process_arg(char* arg, int argPosition);
int convert_arg(char* arg, int defaultValue);
void apply_defaults();
bool output_quadrant(quadrantType q);
double get_x(int theta);
double get_y(int theta);
double transform_x_for_quadrant(double x, quadrantType q);
double transform_y_for_quadrant(double y, quadrantType q);
double shift_x_for_center(double x);
double shift_y_for_center(double y);
bool is_in_domain(int theta);
bool is_in_range(double f);

int main(int argc, char *argv[])
{
    bool result = false;

    result = process_args(argc, argv);

    if (result)
    {
        for (int i = I; i <= IV; i++)
        {
            result = output_quadrant((quadrantType)i);

            if (!result)
            {
                exit(EXIT_FAILURE);
            }
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

    value = sinResultInDegrees * (double)r;
    
    return value;
}

double get_y(int theta)
{
    if (!is_in_domain(theta)) 
        return (double)-1;

    double cosResultInDegrees, value;

    cosResultInDegrees = cos(theta * (M_PI / 180.0));

    value = cosResultInDegrees * (double)r;

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
    value = x - h;
    return value;
}

double shift_y_for_center(double y)
{
    double value = 0;
    value = y - k;
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
    value = (item >= 0 && item <= (double)r);
    return value;
}

bool process_args(int argc, char *argv[])
{
    apply_defaults();
    
    if (argc > 0)
    {
        if (strcmp(argv[1], "?") == 0 ||
            strcmp(argv[1], "-h") == 0 ||
            strcmp(argv[1], "--help") == 0)
        {
            printf("%s [r] [h] [k]\n", argv[0]);
            printf("That's radius then starting coordinates\n");
            return false;
        }
        if (argc > 1)
        {
            r = process_arg(argv[1], 1);
            if (argc > 2)
            {
                h = process_arg(argv[2], 2);
                if (argc > 3)
                {
                    k = process_arg(argv[3], 3);
                }
            }
        }
    }
    return true;
}

int process_arg(char* arg, int argPosition)
{
    int value = 0;
    switch (argPosition)
    {
        case 1:
            value = convert_arg(arg, r);
            break;
        case 2:
            value = convert_arg(arg, h);
            break;
        case 3:
            value = convert_arg(arg, k);
            break;
    }
    return value;
}

int convert_arg(char* arg, int defaultValue)
{
    int value;
    value = atoi(arg);
    if (value == 0)
    {
        value = defaultValue;
    }
    return value;
}

void apply_defaults()
{
    r = 5;
    h = 0;
    k = 0;
}

