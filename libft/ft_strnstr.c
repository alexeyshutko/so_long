/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:39:36 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/23 19:41:26 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	lok;

	if (!*to_find)
		return ((char *)str);
	lok = 0;
	while (str[lok] != '\0' && (size_t)lok < len)
	{
		if (str[lok] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[lok + i] == to_find[i]
				&& (size_t)(lok + i) < len)
			{
				++i;
			}
			if (to_find[i] == '\0')
				return ((char *)&str[lok]);
		}
		++lok;
	}
	return (0);
}
