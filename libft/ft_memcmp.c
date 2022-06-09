/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:38:25 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:39:06 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	size_t			z;
	unsigned char	*stroka1;
	unsigned char	*stroka2;

	z = 0;
	if (num == 0)
		return (0);
	stroka1 = (unsigned char *) memptr1;
	stroka2 = (unsigned char *) memptr2;
	while (*stroka1 == *stroka2 && ++z < num)
	{
		stroka1++;
		stroka2++;
	}
	return ((int)(*stroka1 - *stroka2));
}
