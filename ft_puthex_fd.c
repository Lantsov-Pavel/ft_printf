/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:16:03 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/14 17:32:47 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(char *hex_form, size_t unum, int fd)
{
	int count;
	
	count = 0;
	if (unum >= 16)
		count += ft_puthex_fd(hex_form, unum / 16, fd);
	ft_putchar_fd(hex_form[unum % 16], fd);
	count++;
	return count;
}
