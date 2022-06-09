/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:38:32 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/23 19:40:48 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest && !src)
		return (NULL);
	if (src <= dest)
		while (len--)
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	else
		ft_memcpy(dest, src, len);
	return ((void *)dest);
}
