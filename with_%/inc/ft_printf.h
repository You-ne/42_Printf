/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:19:56 by yotillar          #+#    #+#             */
/*   Updated: 2021/05/11 22:24:11 by yotillar         ###   ########.fr       */
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

# define NB_SPECS		9
# define NB_FLAGS		4

typedef	struct	s_spec
{
	char		c;
	int			(*ptr)();
}				t_spec;

typedef struct	s_data
{
	int			ret;
	int			f[NB_FLAGS];
	char		spe;
	char		*s;
	char		*ft;
	int			fi;
	char		buff[128];
	int			bi;
	va_list		va;
	int			zero;
}				t_data;

/*
**--------------------------------- Prototypes ---------------------------------
*/

int				ft_printf(const char *format, ...);
int				ft_dispatch(t_data *d);
void			ft_buffing(char c, t_data *d);
void			ft_display(t_data *d);
void			ft_end(t_data *d);

void			ft_init(t_data *d);
void			ft_initialize_specs(t_spec *specs);
void			ft_check_initialize(t_data *d);

int				ft_check(t_data *d);
void			ft_check_flags(t_data *d);
void			ft_check_width(t_data *d);
void			ft_check_prec(t_data *d);

void			ft_handler_char(t_data *d);
void			ft_handler_num(t_data *d);

int				ft_sign(t_data *d, size_t *i);
int				ft_hash(t_data *d);

void			ft_num_width(t_data *d);
void			ft_num_minus(t_data *d, size_t len);
void			ft_num_zero(t_data *d, size_t len);
void			ft_num_only_prec(t_data *d);

void			ft_char_minus(t_data *d, size_t len);
void			ft_char_width(t_data *d, size_t len);

int				ft_c_spec(t_data *d);
int				ft_conv_c(t_data *d);
int				ft_d_spec(t_data *d);
int				ft_p_spec(t_data *d);
int				ft_s_spec(t_data *d);
int				ft_u_spec(t_data *d);
int				ft_x_spec(t_data *d);
int				ft_o_spec(t_data *d);
int				ft_n_spec(t_data *d);
int				ft_pct(t_data *d);
void			ft_null(t_data *d);

int				ft_atoi(const char *str);
char			*ft_itoa_base(long nbr, char *base);
long			ft_min(long a, long b);
long			ft_max(long a, long b);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
int				ft_isdigit(int c);
#endif
