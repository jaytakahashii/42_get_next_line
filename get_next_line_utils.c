#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newarray;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newarray = (char *)malloc(sizeof(char) * (len + 1));
	if (!newarray)
		return (NULL);
	ft_strlcpy(newarray, s1, len + 1);
	ft_strlcat(newarray, s2, len + 1);
	return (newarray);
}
