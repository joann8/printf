/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:34:43 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 13:51:25 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_H
# define PF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				b_flag_minus;
	int				b_flag_zero;
	int				b_width;
	unsigned int	v_width;
	int				b_star_width;
	int				b_precision;
	unsigned int	v_length;
	int				b_star_length;
}					flag_list;

typedef struct		a_list
{
	char			c_init;
	int				(*f)(va_list, int*, flag_list*);
}					arg_list;

int				ft_printf(const char *input, ...);
char			*ft_strdup_pf(const char *s, unsigned int start, unsigned int stop);
char 			*ft_strdup(const char *s);
void	 		ft_putstr(char *s);
size_t			ft_strlen(const char *str);
unsigned int	ft_atoi_printf(const char *str, unsigned int *pos, flag_list *flags);
arg_list		*struct_init(void);
int				ft_char(va_list args, int *res, flag_list *flags);
void			ft_char_right(char car, char *c, unsigned int width, int mod);
void			ft_char_left(char car, char *c, unsigned int width);
void			display_char(char car, unsigned int size, flag_list *flags, char *c);
void			display_c(char *c, int *res);

int				ft_p(va_list args, int *res, flag_list *flags);
void			free_p(char *s1, char *s2);
void			ft_add_left(char *tmp, char *tmp1, unsigned int width);
void			ft_add_right(char *tmp, char *tmp1, unsigned int width);

int				is_a_type(char c);
void			flag_init(flag_list *flags);

int				ft_x(va_list args, int *res, flag_list *flags);
int				ft_bigx(va_list args, int *res, flag_list *flags);

int				ft_int(va_list args, int *res, flag_list *flags);
int				ft_unsint(va_list args, int *res, flag_list *flags);
void			manage_negative(char *s, char *tmp, unsigned int *dif, unsigned int *i);
void			ft_int_left(char *s, char *tmp, unsigned int width,	unsigned int length);
void			ft_int_left_np(char *s, char *tmp, unsigned int width, unsigned int length);
void			ft_int_right(char *s, char *tmp, unsigned int width, unsigned int length);
void			ft_int_right_0(char *s, char *tmp, unsigned int width, unsigned int length);
void			display_int(char *tmp1, int *res, char *tmp);
int				manage_precision_0(flag_list *flags, char *tmp);
void			int_format(flag_list *flags, char *tmp, unsigned int *width, unsigned int *length);
void			change_size(unsigned int *size, char *tmp, unsigned int *width, unsigned int *length);
char			*create_int(char *tmp, flag_list *flags, unsigned int width, unsigned int length);

void			man_neg(int n, unsigned int *nbr, unsigned int *size, int mod);
char			*ft_itoa_int(int n);
char			*ft_itoa_unsint(unsigned int n);
char			*ft_itoa_x(unsigned int n, char letter);
void			fill_table(unsigned int n, char *tab, int size, char letter);

void			ft_width(flag_list *flags, va_list args);
void			ft_length(flag_list *flags, va_list args);
void			flag_parsing_width(flag_list *flags, char *str, unsigned int *index);
void			flag_parsing_precision(flag_list *flags, char *str, unsigned int *index);
int				flag_parsing(flag_list *flags, char *str, unsigned int *pos, va_list args);

void			display_percent(char car, unsigned int size, flag_list *flags, char *c);
int				ft_percent(va_list args, int *res, flag_list *flags);

void			fill_table_hexa(unsigned long n, char *tab, int size, flag_list *flags);
void			manage_neg_hexa(long n, unsigned long *nb);
char			*ft_putadd(void *add, flag_list *flags);

int				ft_string(va_list args, int *res, flag_list *flags);
void			display_string(char *tmp, int *res, char *s, int bol);
void			string_help(flag_list *flags, unsigned int *width, unsigned int *length, char *s);
char			*string_null(int *bol, flag_list *flags);
void			ft_string_left(char *s, char *tmp, unsigned int width, unsigned int length);
void			ft_string_right(char *s, char *tmp, unsigned int width,	unsigned int length);

#endif
