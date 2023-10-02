/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:14:26 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/02 19:19:08 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all_str(int fd, char file_str)
{
	char	*buf;
	size_t	read_byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte = 1;
	while (!(strchr(file_str, '\n')) && read_byte)
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
	static char	*all_str;
	char		next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_str = read_all_str(fd, all_str);
	if (!all_str)
		return (NULL);
	next_line = search_
}
