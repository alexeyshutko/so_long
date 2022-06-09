/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:39:34 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/23 20:46:51 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	unsigned int	j;

	j = 0;
	while (s1[j] != '\0' && s2[j] != '\0' && j < num)
	{
		if ((unsigned char)s1[j] != (unsigned char)s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		++j;
	}
	if (j != num)
		return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	return (0);
}
