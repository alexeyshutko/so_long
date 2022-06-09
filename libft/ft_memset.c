/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:27:34 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:31:01 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memset(void *buf, int val, size_t count)
{
	unsigned char	*mem;

	mem = (unsigned char *)buf;
	while (count > 0)
	{
		mem[count - 1] = val;
		count--;
	}
	return (buf);
}
