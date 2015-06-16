#include <math.h>

#include "coord.h"
#include "map.h"
#include "player.h"

void	init_player(struct s_player *player)
{
  player->orientation = 0;
  player->position = coordonne(2500, 3500);
  player->speed = SPEED;
}

void	moove_player(struct s_map *map, struct s_player *player, int moove)
{
  coord	vector;

  vector = coordonne(cosf(RAD(player->orientation)),
		     sinf(RAD(player->orientation)));
  vector = coord_mult(vector, moove * player->speed);
  player->position = coord_sum(player->position, vector);
  if (point_is_in_wall(map, player->position))
    {
      vector = coord_mult(vector, -1);
      player->position = coord_sum(player->position, vector);
    }
}

