#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

/*
 * Note to any Epitech student that would be searching here for a get_next_line:
 *
 * I made this one dirty (and not perfect by the way) especially because I didn't
 * want it to be copied :p
 *
 * By the way, that kind of cheat is easily spotted by your sutdent staff team,
 * so go find another way to cheat.
 */

char		*get_next_line(const int fd)
{
  static char	*last_buffer;
  static int	pc;
  static int	read_size;
  char		*line;
  int		i;
  int		size;

  line = NULL;
  i = 0;
  size = 0;
  while (line == NULL || i == 0 || line[i - 1] != '\n')
    {
      if (pc == read_size)
	{
	  pc = 0;
	  if (last_buffer != NULL)
	    free(last_buffer);
	  last_buffer = NULL;
	}
      if (last_buffer == NULL)
	{
	  last_buffer = malloc(sizeof(char) * SIZE);
	  if ((read_size = read(fd, last_buffer, SIZE)) <= 0)
	    return (line);
	  last_buffer[read_size] = '\0';
	}
      if (i == size)
	{
	  size += SIZE;
	  line = realloc(line, size);
	}
      line[i++] = last_buffer[pc++];
    }
  line[i - 1] = '\0';
  return (line);
}

