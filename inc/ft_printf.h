/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:19:56 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 05:24:34 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


/*
**---------------------------------- Headers -----------------------------------
*/

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
/*
**-------------------------------- Structure & Define --------------------------
*/

# define ARG			d->arg
# define NB_SPECS		10
# define NB_FLAGS		7
# define ZERO			d->flags[0]
# define MINUS			d->flags[1]
# define WIDTH			d->flags[2]
# define PREC			d->flags[3]
# define PLUS			d->flags[4]
# define SPACE			d->flags[5]
# define HASH			d->flags[6]
# define FMT			d->frmt
# define FI				d->fi

typedef	struct	s_spec
{
	char		c;
	int			(*ptr)();
}		t_spec;

// |0  | 1 |   2   |  3   | 4 |  5  | 6 |
//---------------------------------------
// | 0 | - | width | prec | + | ' ' | # |

typedef struct	s_data
{
	int			ret;
	int			flags[NB_FLAGS];
	char 		spe;
	char		*arg;
	char		*frmt;
	int			fi;
	char		buff[128];
	int			bi;
	va_list		args;
}		t_data;

/*
**--------------------------------- Prototypes ---------------------------------
*/

int		ft_printf (const char *format, ...);
int		ft_dispatch(t_data *d);
void	ft_buffing(char c, t_data *d);
void	ft_display(t_data *d);
void	ft_end(t_data *d);

void	ft_init(t_data *d);
void	ft_initialize_specs(t_spec *specs);
void	ft_check_initialize(t_data *d);

int		ft_check(t_data *d);
void	ft_check_flags(t_data *d);
void	ft_check_width(t_data *d);
void	ft_check_prec(t_data *d);

void	ft_handler_char(t_data *d);
void	ft_handler_num(t_data *d);

int		ft_sign(t_data *d, size_t *i);
int		ft_hash(t_data *d);

void	ft_num_width(t_data *d);
void	ft_num_minus(t_data *d, size_t len);
void	ft_num_zero(t_data *d, size_t len);
void	ft_num_only_prec(t_data *d);

void	ft_char_minus(t_data *d, size_t len);
void	ft_char_width(t_data *d, size_t len);

int		ft_c_spec(t_data *d);
int		ft_conv_c(t_data *d);
int		ft_d_spec(t_data *d);
int		ft_p_spec(t_data *d);
int		ft_s_spec(t_data *d);
int		ft_u_spec(t_data *d);
int		ft_x_spec(t_data *d);
int		ft_o_spec(t_data *d);
int		ft_n_spec(t_data *d);
void	ft_null(t_data *d);

int		ft_atoi(const char *str);
char	*ft_itoa_base(uintmax_t value, uintmax_t base, int neg);
char	*ft_itoa_base2(uintmax_t value, uintmax_t base);
long	ft_min(long a, long b);
long	ft_max(long a, long b);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);
#endif
