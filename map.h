#ifndef MAP_H_
# define MAP_H_

# include "wolf.h"

bool	point_is_in_wall(struct s_map *map, coord point);
int	read_map(struct s_map *map, char *name);
void	destroy_map(struct s_map *map);

#endif /* MAP_H_ */

