/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:10:37 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 03:15:40 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean(char **arr)
{
	unsigned int	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		count++;
	}
	free(arr);
	return (NULL);
}

static size_t	ft_count(const char *arr, char c)
{
	size_t	count;

	count = 0;
	while (arr[count] && arr[count] != c)
		count++;
	return (count);
}

static size_t	ft_word(const char*arr, char c)
{
	size_t	k;
	size_t	count;

	k = 0;
	count = 0;
	while (arr[k])
	{
		if ((arr[k] != c && arr[k + 1] && arr[k + 1] == c)
			|| (arr[k] != c && !arr[k + 1]))
			count++;
		k++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	k;
	char	**arr;

	k = 0;
	start = 0;
	if (!s)
		return (NULL);
	arr = malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[k++] == c)
		start++;
	k = -1;
	while (++k < ft_word(s, c))
	{
		arr[k] = ft_substr(s, start, ft_count(&s[start], c));
		if (!arr)
			return (ft_clean(arr));
		start += ft_count(&s[start], c);
		while (s[start] == c)
			start++;
	}
	arr[k] = NULL;
	return (arr);
}
