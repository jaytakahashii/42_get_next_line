/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:14:26 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/05 11:32:13 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_file_str(char *file_str)
{
	size_t	i;
	size_t	j;
	char	*new_file_str;

	i = 0;
	j = 0;
	while (file_str[i] && file_str[i] != '\n')
		i++;
	if (!file_str[i])
		return (NULL);
	new_file_str = malloc(sizeof(char) * ((ft_strlen(file_str) - i) + 1));
	if (!new_file_str)
		return (NULL);
	i++;
	while (file_str[i])
		new_file_str[j++] = file_str[i++];
	new_file_str[j] = '\0';
	return (new_file_str);
}

char	*search_indention(char *file_str)
{
	size_t	index;
	char	*next_line;

	index = 0;
	while (file_str[index] && file_str[index] != '\n')
		index++;
	next_line = malloc(sizeof(char) * (index + 2));
	if (!next_line)
		return (NULL);
	index = 0;
	while (file_str[index] && file_str[index] != '\n')
	{
		next_line[index] = file_str[index];
		index++;
	}
	if (file_str[index] == '\n')
	{
		next_line[index] = '\n';
		index++;
	}
	next_line[index] = '\0';
	return (next_line);
}

char	*read_file_str(int fd, char *file_str)
{
	char	*buf;
	int		read_byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte = 1;
	while ((ft_strchr(file_str, '\n') == NULL) && read_byte)
	{
		read_byte = read(fd, (void *)buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		file_str = ft_strjoin(file_str, buf);
	}
	free(buf);
	return (file_str);
}


char	*get_next_line(int fd)
{
	static char	*file_str;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_str = read_file_str(fd, file_str);
	if (!file_str)
		return (NULL);
	next_line = search_indention(file_str);
	file_str = new_file_str(file_str);
	return (next_line);
}

// #include <stdio.h>
// #include <fcntl.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test/test1.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	return (0);
// }
