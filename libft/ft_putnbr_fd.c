/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:27:41 by gpolyxen          #+#    #+#             */
/*   Updated: 2021/10/26 02:30:35 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	k;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		k = (unsigned int)(nb * -1);
	}
	else
		k = (unsigned int)nb;
	if (k >= 10)
		ft_putnbr_fd(k / 10, fd);
	ft_putchar_fd((char)(k % 10 + 48), fd);
}
