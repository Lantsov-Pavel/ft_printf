/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plantsov <plantsov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:30:06 by plantsov          #+#    #+#             */
/*   Updated: 2025/01/22 15:30:08 by plantsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int	    ft_printf(const char *input, ...);
int	    ft_print_ptr(va_list args, int fd);
int     ft_print_nbr(char c, va_list args, int fd);
int	    ft_print_str(va_list args, int fd);
int     ft_print_chr(char c, va_list args, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int     ft_puthex_fd(char *hex_form, size_t unum, int fd);
void	ft_putnbr_fd(int n, int fd);
int	    ft_print_hex(char c, va_list args, int fd);
size_t	ft_strlen(char *str);

#endif
