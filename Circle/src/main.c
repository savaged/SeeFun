#include "circle.h"
#include <stdlib.h>

int main()
{
    bool result = false;

    for (int i = I; i <= IV; i++)
    {
        result = output_quadrant((quadrantType)i);

        if (!result)
        {
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}

