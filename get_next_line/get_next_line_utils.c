#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	if (!(s1 && s2))
		return (0);
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = (char)s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = (char)s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		pos;
	char		*str;

	if (!s)
		return (0);
	pos = 0;
	if (ft_strlen(s) < start)
		len = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (pos < len && s[start] != '\0')
	{
		str[pos] = s[start];
		pos++;
		start++;
	}
	str[pos] = '\0';
	return (str);
}
