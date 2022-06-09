/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:39:07 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:29:19 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strchr(const char *s, int c)
{
	char	*stroka;

	stroka = (char *)s;
	while (*stroka != c)
		  {
		if (*stroka == '\0')
		{
			return (NULL);
		}
		stroka++;
	}
	return (stroka);
}
