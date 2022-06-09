#include "get_next_line.h"

int	find_endl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*cut_str(char **s)
{
	char	*line;
	char	*tmp;

	if (find_endl(*s) != -1)
	{
		line = ft_substr(*s, 0, find_endl(*s) + 1);
		tmp = ft_substr(*s, find_endl(*s) + 1, ft_strlen(*s));
		free(*s);
		*s = NULL;
		*s = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}	
	else
	{
		line = ft_substr(*s, 0, ft_strlen(*s));
		free(*s);
		*s = NULL;
	}
	return (line);
}

char	*back_str(char **rest, char *buf, int fd)
{
	int		how_much_bit;
	char	*str;

	if (find_endl(*rest) != -1)
		return (cut_str(rest));
	how_much_bit = read(fd, buf, BUFFER_SIZE);
	if (how_much_bit <= 0)
	{
		if (**rest)
			return (cut_str(rest));
		else
		{
			free(*rest);
			*rest = NULL;
			return (NULL);
		}
	}
	buf[how_much_bit] = '\0';
	str = ft_strjoin(*rest, buf);
	free(*rest);
	*rest = NULL;
	*rest = ft_strdup(str);
	free(str);
	str = NULL;
	return (back_str(rest, buf, fd));
}

char	*get_next_line(int fd)
{	
	static char	*rest;
	char		*buf;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	line = back_str(&rest, buf, fd);
	free(buf);
	buf = NULL;
	return (line);
}
