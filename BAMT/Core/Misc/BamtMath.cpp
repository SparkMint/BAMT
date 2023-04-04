#include "BamtMath.h"

namespace Math
{
    float Clamp(float value, float minValue, float maxValue)
    {
        if (value < minValue)
        {
            return minValue;
        }
        if (value > maxValue)
        {
            return maxValue;
        }
        return value;
    }
}
