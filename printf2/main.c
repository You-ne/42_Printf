#include "./inc/ft_printf_bonus.h"

int		main()
{
	char	*s;
	s = NULL;
	
	ft_printf("..Printf:");
	printf("%p\n", NULL);
	ft_printf("ft_printf:");
	ft_printf("%p\n", NULL);
	
	ft_printf("..Printf:");
	printf("%5p\n", 0);
	ft_printf("ft_printf:");
	ft_printf("%5p\n", 0);
	
	ft_printf("..Printf:");
	printf("%.*p\n", -3, 0);
	ft_printf("ft_printf:");
	ft_printf("%.*p\n", -3, 0);
	
	ft_printf("..Printf:");
	printf("%.*p\n", -1, 0);
	ft_printf("ft_printf:");
	ft_printf("%.*p\n", -1, 0);
	return(0);
}
