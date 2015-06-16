#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "window.h"

int	get_window_size(int *longer, int *width)
{
  int	pipefd[2];
  int	size;
  pid_t	pid;
  char	buffer[42];
  char	*ptr;

  pipe(pipefd);
  if ((pid = fork()) == 0)
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	exit(1);
      system("stty size");
      close(pipefd[1]);
      exit(0);
    }
  size = read(pipefd[0], buffer, 42);
  if (size <= 0)
    return (1);
  buffer[size] = '\0';


  ptr = strstr(buffer, " ");
  *ptr = '\0';
  *width = atoi(buffer);
  *longer = atoi(ptr + 1);

  close(pipefd[1]);
  close(pipefd[0]);
  return (0);
}

