#include <stdarg.h>
#include <stdio.h>

void	ft_choose_type(char c, va_list args);
void	ft_putchar_fd(char c, int fd);

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

int	main(void)
{
	ft_printf("My: Character: %c\n", 'A');
	printf("Lb: Character: %c\n", 'A');
	ft_printf("My: String: %s\n", "Hello, World!");
	printf("Lb: String: %s\n", "Hello, World!");
	int x = 42;
	ft_printf("My: Pointer: %p\n", (void *)&x);
	printf("Lb: Pointer: %p\n", (void *)&x);
	ft_printf("My: Decimal: %d\n", 123);
	printf("Lb: Decimal: %d\n", 123);
	ft_printf("My: Integer: %i\n", -123);
	printf("Lb: Integer: %i\n", -123);
	ft_printf("My: Unsigned: %u\n", 123U);
	printf("Lb: Unsigned: %u\n", 123U);
	ft_printf("My: Hex lowercase: %x\n", 255);
	printf("Lb: Hex lowercase: %x\n", 255);
	ft_printf("My: Hex uppercase: %X\n", 255);
	printf("Lb: Hex uppercase: %X\n", 255);
	ft_printf("My: Percent sign: %%\n");
	printf("Lb: Percent sign: %%\n");
	return 0;
}
