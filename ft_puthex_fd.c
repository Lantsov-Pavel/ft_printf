#include <stdio.h>

void	ft_putchar_fd(char c, int fd);

void	ft_puthex_fd(char *hex_form, size_t unum, int fd)
{
	if (unum >= 16)
		ft_puthex_fd(hex_form, unum / 16, fd);
	ft_putchar_fd(hex_form[unum % 16], fd); 
}
