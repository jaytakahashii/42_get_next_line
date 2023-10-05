/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:46:06 by jtakahas          #+#    #+#             */
/*   Updated: 2023/10/05 12:05:43 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

static char	*ft_calloc(char *str)
{
	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	size_t	index;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index])
	{
		if (str[index] == (char)c)
			return (str + index);
		index++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!str)
		str = ft_calloc(str);
	if (!str || !buf)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buf[j])
		new_str[i++] = buf[j++];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
