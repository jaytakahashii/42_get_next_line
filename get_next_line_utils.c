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

char	*ft_strjoin(char *file_str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!file_str)
	{
		file_str = malloc(sizeof(char) * 1);
		file_str[0] = '\0';
	}
	if (!file_str || !buf)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(file_str) + ft_strlen(buf)) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	if (file_str)
		while (file_str[i++])
			new_str[i] = file_str[i];
	while (buf[j])
		new_str[i++] = buf[j++];
	new_str[i] = '\0';
	free(file_str);
	return (new_str);
}
