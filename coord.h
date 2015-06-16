#ifndef COORD_H_
# define COORD_H_

# include <math.h>

# define NORM(v)	(sqrtf(v.x * v.x + v.y * v.y))

typedef struct	s_coord
{
  float		x;
  float		y;
}		coord;

coord		coordonne(float x, float y);
float		coord_difference(coord a, coord b);
coord		coord_sum(coord a, coord b);
coord		coord_mult(coord point, float nb);

#endif /* COORD_H_ */

