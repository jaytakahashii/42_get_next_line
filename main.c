#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks a.out");
}

void	*malloc(size_t size)
{
	int	i;

	i = rand() % 10;
	if (i == 0)
		return (NULL);
	return (calloc(1, size));
}

int	main(void)
{
	int		fd;
	char	*line;

	srand(time(NULL));

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	printf("\n\n\n");
	line = get_next_line(1);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
