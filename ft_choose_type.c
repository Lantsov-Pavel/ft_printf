/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:45:12 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/18 18:16:12 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_ptr(va_list args, int fd)
{
	size_t	ptr;

	ptr = (size_t)va_arg(args, void *);
	ft_putstr_fd("0x", fd);
	ft_puthex_fd("0123456789abcdef", ptr, fd);
}

static void	ft_print_chr(char c, va_list args, int fd)
{
	if (c == 'c')
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, fd);
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', fd);
	}
}

static void	ft_print_nbr(char c, va_list args, int fd)
{
	unsigned int	unum;
	size_t			hnum;
	char			*hex_form;
	int				num;

	if (c == 'd' || c == 'i')
	{
		num = va_arg(args, int);
		ft_putnbr_fd(num, fd);
	}
	else if (c == 'u')
	{
		unum = va_arg(args, unsigned int);
		ft_putnbr_fd(unum, fd);
	}
	else if (c == 'x' || c == 'X')
	{
		hnum = va_arg(args, size_t);
		hex_form = "0123456789abcdef";
		if (c == 'X')
			hex_form = "0123456789ABCDEF";
		ft_puthex_fd(hex_form, hnum, fd);
	}
}

static void	ft_print_str(va_list args, int fd)
{
	char	*s;

	s = va_arg(args, char *);
	ft_putstr_fd(s, fd);
}

void	ft_choose_type(char c, va_list args)
{
	int	fd;

	fd = 1;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		ft_print_nbr(c, args, fd);
	else if (c == 'c' || c == '%')
		ft_print_chr(c, args, fd);
	else if (c == 's')
		ft_print_str(args, fd);
	else if (c == 'p')
		ft_print_ptr(args, fd);
}
