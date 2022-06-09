/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:39:23 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:27:47 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	j;
	unsigned int	k;
	char			*result;

	if (!(s1 && s2))
		return (0);
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (0);
	j = -1;
	while (s1[++j] != '\0')
		result[j] = (char)s1[j];
	k = 0;
	while (s2[k] != '\0')
	{
		result[j] = (char)s2[k];
		j++;
		k++;
	}
	result[j] = '\0';
	return (result);
}
