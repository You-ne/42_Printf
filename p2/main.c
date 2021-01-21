#include "./inc/ft_printf_bonus.h"

int		main()
{
	char	*s;
	s = NULL;
	ft_printf("..Printf:");
	printf("%.03s\n", s);
	ft_printf("ft_printf:");
	ft_printf("%0.3s\n", s);
	ft_printf("..Printf:");
	printf("%3.1s\n", s);
	ft_printf("ft_printf:");
	ft_printf("%3.1s\n", s);
	ft_printf("..Printf:");
	printf("%9.1s\n", s);
	ft_printf("ft_printf:");
	ft_printf("%9.1s\n", s);
	ft_printf("..Printf:");
	printf("%-3.1s\n", s);
	ft_printf("ft_printf:");
	ft_printf("%-3.1s\n", s);
	ft_printf("..Printf:");
	printf("%-9.1s\n", s);
	ft_printf("ft_printf:");
	ft_printf("%-9.1s\n", s);
	return(0);
}
