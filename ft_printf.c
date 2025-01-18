/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:47:07 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/14 17:30:01 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;

	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			ft_choose_type(*input, args);
		}
		else
		{
			ft_putchar_fd(*input, 1);
		}
		input++;
	}
	va_end(args);
	return (0);
}
