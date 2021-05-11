#include "inc/ft_printf.h"

int		main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

/*	a = -1;
	while (a < 5)
	{
		printf("%d\n", a);
		printf("Real %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X\n"
		, a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		ft_printf("Mine %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X\n"
		, a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		a++;
	}
*/
	/*
	a = 12;
	b = 18;
	printf("TEST C1\n");
	printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);

	printf("TEST C2\n");
	printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);
	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);

	printf("TEST C3\n");
	printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c);
	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c);
	
	printf("TEST C4\n");
	printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
	
	printf("TEST 510\n");
	printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	
	printf("TEST NULL\n");
	printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);*/
//	printf("My Test\n");
//	printf("\n");
//	ft_printf("\n");
	printf("TEST P NULL\n");
	printf("%.2p\n", NULL);
	ft_printf("%.2p\n", NULL);

	return (0);
}
