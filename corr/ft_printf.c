/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 10:23:03 by edjavid           #+#    #+#             */
/*   Updated: 2021/04/24 11:30:23 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_flags(t_fs *fs, char *s, va_list *ap)
{
	if (*s == '.')
	{
		fs->point = 1;
		fs->zero = 0;
		fs->precision = ft_atoi(++s);
		while (is_adig(*s))
			s++;
		if (*s == '*')
		{
			fs->precision = va_arg(*ap, int);
			s++;
		}
	}
	if (is_adig(*s))
	{
		fs->width = ft_atoi(s);
		while (is_adig(*s))
			s++;
	}
	if (*s == '-')
	{
		fs->minus = 1;
		s++;
	}
	return (s);
}

void	retrieve_arg(t_fs *fs, va_list *ap, char *s)
{
	fs->spec = *s;
	if (*s == 'd' || *s == 'i')
		fs->d = va_arg(*ap, int);
	else if (*s == 's')
		fs->s = va_arg(*ap, char *);
	else if (*s == 'c')
		fs->c = va_arg(*ap, int);
	else if (*s == 'p')
		fs->pt = va_arg(*ap, size_t);
	else if (*s == '%')
		ft_putchar('%', 1, fs);
	else
		fs->u = va_arg(*ap, unsigned int);
}

void	gather_flag(t_fs *fs, char *s, va_list *ap)
{
	while (*s)
	{
		if (s[0] == '0')
		{
			fs->zero = 1;
			s++;
		}
		if (*s == 'd' || *s == 's' || *s == 'x' || *s == 'c' || \
		*s == 'X' || *s == 'p' || *s == 'i' || *s == 'u' || *s == '%')
		{
			retrieve_arg(fs, ap, s);
			++s;
			break ;
		}
		s = get_flags(fs, s, ap);
		s = get_star(fs, s, ap);
	}
	fs->out = s;
}

void	global_print(t_fs *fs)
{
	if (fs->spec == 'd' || fs->spec == 'i')
		correct_dec(fs);
	if (fs->spec == 'u')
	{
		correct_u(fs);
		print_u(fs);
	}
	else if (fs->spec == 'x' || fs->spec == 'X')
	{
		correct_hex(fs);
		print_hex(fs);
	}
	else if (fs->spec == 's')
	{
		correct_str(fs);
		print_str(fs);
	}
	else if (fs->spec == 'c')
		print_c(fs);
	else if (fs->spec == 'p')
	{
		correct_p(fs);
		print_p(fs);
	}
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	t_fs	fs;

	fs.ret = 0;
	va_start(ap, s);
	while (*s)
	{
		while (*s && *s != '%')
			ft_putchar(*s++, 1, &fs);
		if (*s && *s == '%')
		{
			init_flag(&fs);
			gather_flag(&fs, (char *)++s, &ap);
			global_print(&fs);
			s = fs.out;
		}
	}
	return (fs.ret);
}
