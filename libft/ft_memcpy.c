/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:38:29 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:31:48 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*l;
	const unsigned char	*z;

	if (!dest && !src)
		return (NULL);
	l = dest;
	z = src;
	while (n-- > 0)
		*(l++) = *(z++);
	return (dest);
}
