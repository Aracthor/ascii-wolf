#ifndef PLAYER_H_
# define PLAYER_H_

# include "wolf.h"

# define SPEED	(20)

void	init_player(struct s_player *player);
void	moove_player(struct s_map *map, struct s_player *player, int moove);

#endif /* PLAYER_H_ */

