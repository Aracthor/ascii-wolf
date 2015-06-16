#ifndef WOLF_H_
# define WOLF_H_

# include "coord.h"

# define RAD(angle)	((float)(angle) * 3.14 / 180)

typedef enum	e_bool
{
  false,
  true
}		bool;

typedef enum	e_case
{
  empty,
  wall
}		t_case;

typedef struct	s_map
{
  int		longer;
  int		larger;
  enum e_case	**cases;
}		t_map;

typedef struct	s_player
{
  int		orientation;
  int		speed;
  coord		position;
}		t_player;

typedef struct	s_img
{
  int		longer;
  int		larger;
  char		**data;
}		t_img;

#endif /* WOLF_H_ */

