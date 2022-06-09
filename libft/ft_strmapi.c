/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:39:31 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:25:35 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	j;
	char			*stroka;

	j = -1;
	if (!s)
		return (0);
	stroka = malloc((size_t)ft_strlen((char *)s) + 1);
	if (!s || !stroka)
		return (NULL);
	while (s[++j])
	{
		stroka[j] = f(j, s[j]);
	}
	stroka[j] = '\0';
	return (stroka);
}
