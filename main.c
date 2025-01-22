#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	x;

	ft_printf("My: Character: %c\n", 'A');
	printf("Lb: Character: %c\n", 'A');
	ft_printf("My: String: %s\n", "Hello, World!");
	printf("Lb: String: %s\n", "Hello, World!");
	x = 42;
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
	return (0);
}
