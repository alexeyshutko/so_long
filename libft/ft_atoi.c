/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:37:38 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 03:24:26 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_proverka(const char *stroka, int sign, int i)
{
	long	result;

	result = 0;
	while (stroka[i] != '\0' && (stroka[i] >= '0' && stroka[i] <= '9'))
	{
		if (result == 922337203685477580 && stroka[i] > '7')
		{
			if (sign == -1 && stroka[i] > '8')
				return ((long)(0));
			if (sign == 1)
				return ((long)(-1));
		}
		if (result > 922337203685477580)
		{
			if (sign == -1)
				return ((long)(0));
			if (sign == 1)
				return ((long)(-1));
		}
		result = (result * 10) + (stroka[i] - '0');
		i++;
	}
	return ((long)(result * sign));
}

int	ft_atoi(const char *stroka)
{
	int		f;
	int		i;
	long	result;
	int		sign;

	f = 0;
	while (stroka[f] == ' ' || (stroka[f] >= 9 && stroka[f] <= 13))
		f++;
	i = f;
	sign = 1;
	result = 0;
	if (stroka[f] == '-' || stroka[f] == '+')
	{
		if (stroka[f] == '-')
			sign = -1;
		i++;
	}
	return ((long)(ft_proverka(stroka, sign, i)));
}
