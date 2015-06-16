#include <math.h>
#include <stdlib.h>

#include "coord.h"

coord	coordonne(float x, float y)
{
  coord	coords;

  coords.x = x;
  coords.y = y;
  return (coords);
}

float	coord_difference(coord a, coord b)
{
  float	x_diff;
  float	y_diff;

  x_diff = abs(a.x - b.x);
  y_diff = abs(a.y - b.y);
  return (sqrtf(x_diff * x_diff + y_diff * y_diff));
}

coord	coord_sum(coord a, coord b)
{
  return (coordonne(a.x + b.x, a.y + b.y));
}

coord	coord_mult(coord point, float nb)
{
  return (coordonne(point.x * nb, point.y * nb));
}

