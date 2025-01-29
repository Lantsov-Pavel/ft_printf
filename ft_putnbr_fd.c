/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:05:41 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/14 17:12:07 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_fd(int n, int fd)
{
	char	c;
	int 	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return(11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			count++;
		}
		if (n >= 10)
			count += ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
		count++;
	}
	return(count);
}
