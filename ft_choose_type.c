#include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);


ft_print_chr(char c, va_list args, int fd)
{
    if(c == 'c')
    {
        c = (char)va_arg(args, int);
        ft_putchar_fd(c, fd);
    }
    else if(c == '%')
    {
        ft_putchar_fd('%', fd);
    }
}

void    ft_print_nbr(char c, va_list args, int fd)
{
    int num;
    unsigned unum;

    if(c == 'd' || c == 'i')
    {
        num = va_arg(args, int);
		ft_putnbr_fd(num, fd);
    } 
    else if(c == 'u')
    {
        unum = va_arg(args, unsigned int);
		ft_putnbr_fd(unum, fd);
    }
}

void	ft_print_str(va_list args, int fd)
{
	char *s;
    s = va_arg(args, char*);
    ft_putstr_fd(s, fd);
}

void	ft_choose_type(char c, va_list args)
{
	int fd;
	fd = 1;
	if(c == 'd' || c == 'i' || c == 'u')
		ft_print_nbr(c, args, fd);
	//else if(c == 'x' || c == 'X' || c == 'p')
		//print_hd_nbr(c,  args);
	else if(c == 'c' || c == '%')
		ft_print_chr(c,  args, fd);
	else if(c == 's')
		ft_print_str(args, fd);
}