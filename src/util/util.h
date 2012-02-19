#ifndef UTIL_H_
#define UTIL_H_

#include <math.h>
#include <stdio.h>

struct Coordinate
{
    double lat;
    double lon;
};

class Util
{
public:
    static const double DEG_TO_RAD;
    static const double EARTH_RADIUS_IN_METERS;

    static double arcInRadians(const Coordinate& from, const Coordinate& to);
    static double distanceInMeters(const Coordinate& from, const Coordinate& to);
};

#endif /* UTIL_H_ */
