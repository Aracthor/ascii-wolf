#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "get_next_line.h"
#include "map.h"

bool	point_is_in_wall(struct s_map *map, coord point)
{
  if (map->cases[(int)(point.y / 1000)][(int)(point.x / 1000)] != empty)
    return (true);
  else
    return (false);
}

static int	read_map_size(struct s_map *map, const int fd)
{
  int		i;
  char		*line;
  char		*ptr;

  if ((line = get_next_line(fd)) == NULL || (ptr = strstr(line, "|")) == NULL)
    return (1);
  *ptr = '\0';
  map->longer = atoi(line);
  map->larger = atoi(ptr + 1);
  map->cases = malloc(sizeof(enum e_case *) * map->larger);
  for (i = 0; i < map->larger; ++i)
    map->cases[i] = malloc(sizeof(enum e_case) * map->longer);
  free(line);

  return (0);
}

static t_case	*read_map_line(char *line, enum e_case *map_line, int longer)
{
  int		i;

  for (i = 0; line[i] != '\0'; ++i)
    {
      if (i % 2 == 0)
	{
	  if (i / 2 >= longer || (line[i] != '0' && line[i] != '1'))
	    return (NULL);
	  else switch (line[i])
	    {
	    case ('0'):
	      map_line[i / 2] = empty;
	      break;
	    case ('1'):
	      map_line[i / 2] = wall;
	      break;
	    }
	}
      else if (line[i] != '.')
	return (NULL);
    }

  if ((i + 1) / 2 != longer)
    return (NULL);

  return (map_line);
}

int	read_map(struct s_map *map, char *name)
{
  int	fd;
  int	i;
  char	*line;

  fd = open(name, O_RDONLY);
  i = 0;
  if (read_map_size(map, fd) != 0)
    return (1);

  while ((line = get_next_line(fd)) != NULL && line[0] != '\0')
    {
      if (i >= map->larger ||
	  (map->cases[i] = read_map_line(line, map->cases[i], map->longer))
	   == NULL)
	return (1);
      ++i;
      free(line);
    }

  if (line != NULL)
    free(line);
  if (i != map->larger)
    return (1);

  return (0);
}

void	destroy_map(struct s_map *map)
{
  int	i;

  for (i = 0; i < map->larger; ++i)
    free(map->cases[i]);
  free(map->cases);
}

