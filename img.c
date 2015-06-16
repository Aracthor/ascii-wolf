#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "gere_img.h"
#include "img.h"
#include "window.h"

struct s_map		*g_map;
struct s_player		*g_player;
struct s_img		*g_img;

void			create_img(struct s_img *img)
{
  int			i;

  get_window_size(&img->longer, &img->larger);
  img->data = malloc(sizeof(char *) * img->larger);
  for (i = 0; i < img->larger; ++i)
    img->data[i] = malloc(sizeof(char) * img->longer);
}

void	resize_img(struct s_img *img)
{
  destroy_img(img);
  create_img(img);
}

void	print_img(struct s_img *img)
{
  int	x;
  int	y;
  char	*display;

  display = malloc(sizeof(char) * img->longer * img->larger + 7);
  display[0] = '\0';
  /* strcpy(display, "\033[H\033[ J"); */
  for (y = 0; y < img->larger; ++y)
    for (x = 0; x < img->longer; ++x)
      display[y * img->longer + x] = img->data[y][x];
  write(1, display, img->longer * img->larger + 7);
  free(display);
}

void	destroy_img(struct s_img *img)
{
  int	i;

  for (i = 0; i < img->larger; ++i)
    free(img->data[i]);
  free(img->data);
}

void	resize_window()
{
  resize_img(g_img);
  gere_img(g_map, g_player, g_img);
}

