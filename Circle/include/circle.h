#include <stdbool.h>

#define r 5
#define h 3
#define k 2

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

