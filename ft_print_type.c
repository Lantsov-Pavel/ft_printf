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

#include "ft_printf.h"

int	ft_print_ptr(va_list args, int fd)
{
	size_t	ptr;
	int result;

	result = 2;
	ptr = (size_t)va_arg(args, void *);
	ft_putstr_fd("0x", fd);
	result += ft_puthex_fd("0123456789abcdef", ptr, fd);
	return (result);
}

int	ft_print_chr(char c, va_list args, int fd)
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
	return (1);
}

int	ft_print_nbr(char c, va_list args, int fd)
{
	unsigned int	unum;
	int				num;
	int				result;

	result = 1;
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
	return (result);
}

int	ft_print_str(va_list args, int fd)
{
	char	*s;
	int result;
	s = va_arg(args, char *);
	result = ft_strlen(s);
	ft_putstr_fd(s, fd);
	return (result);
}

int ft_print_hex(char c, va_list args, int fd)
{
	size_t		hnum;
	char		*hex_form;
	int			result;

	hnum = va_arg(args, size_t);
	hex_form = "0123456789abcdef";
	if (c == 'X')
		hex_form = "0123456789ABCDEF";
	result = ft_puthex_fd(hex_form, hnum, fd);
	return (result);
}