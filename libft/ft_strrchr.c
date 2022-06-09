/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:39:39 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/23 20:00:44 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int	len;

	len = ft_strlen((char *)str);
	while (0 != len && str[len] != (char)s)
		len--;
	if (str[len] == (char)s)
		return ((char *)&str[len]);
	return (NULL);
}
