/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:37:56 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:01:34 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	bit;
	void			*addr;

	bit = nmemb * size;
	addr = malloc(bit);
	if (addr)
		ft_memset(addr, 0, bit);
	return (addr);
}
