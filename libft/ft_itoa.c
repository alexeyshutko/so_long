/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:38:18 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 03:35:39 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numbers(int z)
{
	int	kolicestvo;
	int	summa;

	if (z == 0)
		return (1);
	kolicestvo = 0;
	summa = z;
	while (z != 0)
	{
		z = z % 10;
		summa = summa / 10;
		z = summa;
		kolicestvo++;
	}
	return (kolicestvo);
}

static int	ft_enter(int z)
{
	if (z < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int z)
{
	char	*string;
	int		enter;
	int		numer;
	int		summa;

	enter = ft_enter(z);
	numer = ft_numbers(z) + 1 + (z < 0);
	string = (char *)malloc(sizeof(char) * numer);
	if (!string)
		return (NULL);
	ft_bzero(string, numer);
	if (z == 0)
		string[0] = '0';
	summa = z;
	numer = numer - 2;
	while (z != 0)
	{
		z = z % 10;
		string[numer--] = z * enter + '0';
		summa = summa / 10;
		z = summa;
	}
	if (enter < 0)
		string[numer] = '-';
	return (string);
}
