#include <stdarg.h>

/*
%c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign
*/
void	ft_choose_type(char c, va_list args);
void	ft_putchar_fd(char c, int fd);

int ft_printf(const char *input, ...)
{
	va_list args;
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
            ft_putchar_fd(input, 1);
        }
        input++;
    }
    va_end(args);
    return (0);
}

int main()
{
    ft_printf("1341512 %d %c %s", 10, 'c', "1234566");
    ft_printf("%%");
    ft_printf("%s", "test");
    return (0);
}
