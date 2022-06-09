/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:38:22 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:33:09 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			j;
	unsigned char	*stroka;
	unsigned char	character;

	stroka = (unsigned char *)arr;
	character = (unsigned char)c;
	j = 0;
	while (j < n)
	{
		if (*stroka == character)
		{
			return (stroka);
		}
		stroka++;
		j++;
	}
	return (NULL);
}
