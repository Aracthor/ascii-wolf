#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include "gere_img.h"
#include "img.h"
#include "keyboard.h"
#include "map.h"
#include "player.h"
#include "termcaps.h"

struct s_map	*g_map;
struct s_player	*g_player;
struct s_img	*g_img;

void	game_loop(struct s_map *map, struct s_player *player, struct s_img *img)
{
  bool	loop;
  int	key;

  loop = true;
  gere_img(map, player, img);
  while (loop)
    {
      key = 0;
      read(0, &key, 4);
      switch (key)
	{
	case (ESCAPE):
	  loop = false;
	  break;
	case (UP):
	  moove_player(map, player, 1);
	  break;
	case (DOWN):
	  moove_player(map, player, -1);
	  break;
	case (RIGHT):
	  player->orientation += 5;
	  break;
	case (LEFT):
	  player->orientation -= 5;
	  break;
	}
      if (loop)
	gere_img(map, player, img);
    }
}

int			main(int argc, char **argv)
{
  struct s_map		map;
  struct s_player	player;
  struct s_img		img;

  if (argc == 1)
    {
      fprintf(stderr, "Please enter a map.\n");
      return (2);
    }

  if (read_map(&map, argv[1]) != 0)
    {
      fprintf(stderr, "Corruted map.\n");
      return (1);
    }
  init_player(&player);
  create_img(&img);

  g_map = &map;
  g_player = &player;
  g_img = &img;

  signal(SIGWINCH, &resize_window);

  cannon_mode(ENABLE);

  game_loop(&map, &player, &img);

  cannon_mode(DISABLE);

  destroy_map(&map);

  return (0);
}

