/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:35:37 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:26:45 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	r;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (dst[i] && i < size)
		++i;
	r = ft_strlen(src);
	while ((src[++j]) && ((i + j + 1) < size))
		dst[i + j] = src[j];
	if (i != size)
		dst[i + j] = '\0';
	return (i + r);
}
