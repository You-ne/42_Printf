/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:34:18 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/14 13:29:28 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_fs
{
	char			spec;
	int				width;
	int				sign;
	int				precision;
	int				point;
	int				minus;
	int				len;
	int				d;
	unsigned int	u;
	long			l;
	char			*s;
	char			c;
	char			*out;
	int				ret;
	int				zero;
	size_t			pt;
}				t_fs;

int				ft_printf(const char *s, ...);
void			print_c(t_fs *fs);
void			correct_str(t_fs *fs);
void			print_str(t_fs *fs);
void			ft_putstr(char *s, t_fs *fs);
void			ft_putchar(char c, int n, t_fs *fs);
int				len(char *s);
int				ft_atoi(char *s);
char			hex_dig(int	n);
char			*hex_conv(unsigned int u, int step);
void			convert_big_x(t_fs *fs);
void			correct_hex(t_fs *fs);
void			print_hex(t_fs *fs);
void			print_hex_p(size_t n, t_fs *fs);
void			print_p(t_fs *fs);
int				ptlen(unsigned int u);
void			correct_p(t_fs *fs);
int				nbrlen(int n);
void			correct_dec(t_fs *fs);
void			ft_putnbr(long l, t_fs *fs);
void			print_dec(t_fs *fs);
int				ulen(unsigned long long n);
void			correct_u(t_fs *fs);
void			print_u(t_fs *fs);
void			init_flag(t_fs *fs);
char			*get_star(t_fs *fs, char *s, va_list *ap);
int				is_adig(char c);

#endif
