#include <math.h>
#include <string.h>

#include "coord.h"
#include "gere_img.h"
#include "img.h"
#include "map.h"

static float	calc_distance(struct s_map *map, struct s_player *player,
			      struct s_img *img, coord vector, char *wall, float ratio)
{
  coord		point;
  float		distance;

  point = player->position;

  while (!point_is_in_wall(map, point))
    point = coord_sum(point, vector);
  vector = coord_mult(vector, -0.1f);
  while (point_is_in_wall(map, point))
    point = coord_sum(point, vector);
  vector = coord_mult(vector, -0.1f);
  while (!point_is_in_wall(map, point))
    point = coord_sum(point, vector);

  if ((int)(point.x) % 1000 == 0 || (int)(point.x) % 1000 == 999)
    *wall = '#';
  else
    *wall = '@';

  distance = coord_difference(player->position, point) / ratio * 10;

  return (distance);
}

static void	calc_col(struct s_map *map, struct s_player *player,
			 struct s_img *img, coord vector, int col)
{
  float		distance;
  float		ratio;
  int		wall_size;
  int		y;
  char		wall;

  ratio = NORM(vector);
  distance = calc_distance(map, player, img, vector, &wall, ratio);
  wall_size = (int)((float)(img->larger) * 500.0f / distance);
  if (wall_size > img->larger)
    wall_size = img->larger;

  for (y = img->larger / 2 - wall_size / 2;
       y < img->larger / 2 + wall_size / 2;
       ++y)
    img->data[y][col] = wall;
}

void	gere_img(struct s_map *map, struct s_player *player, struct s_img *img)
{
  coord	vector;
  coord	rotated_vector;
  int	x;

  for (x = 0; x < img->larger; ++x)
    img->data[x] = memset(img->data[x], ' ', img->longer);
  for (x = 0; x < img->longer; ++x)
    {
      vector.x = 10.0f;
      vector.y = ((float)(10.0f * (img->longer - 2.0f * x))
		  / (float)(img->longer));
      rotated_vector.x = (vector.x * cosf(RAD(player->orientation)) + 
			  vector.y * sinf(RAD(player->orientation)));
      rotated_vector.y = (vector.x * sinf(RAD(player->orientation)) +
			  vector.y * -cosf(RAD(player->orientation)));
      calc_col(map, player, img, rotated_vector, x);
    }

  print_img(img);
}

