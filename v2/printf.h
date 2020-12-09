/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:34:43 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 22:47:38 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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
	int				(*f)(va_list, int *, flag_list*);
}					arg_list;

arg_list		*struct_init(void);
int				ft_printf(const char *input, ...);
int				ft_percent(va_list args, int *res, flag_list *flags);
int				ft_char(va_list args, int *res, flag_list *flags);
int				ft_int(va_list args, int *res, flag_list *flags);
int				ft_unsint(va_list args, int *res, flag_list *flags);
int				ft_x(va_list args, int *res, flag_list *flags);
int				ft_bigx(va_list args, int *res, flag_list *flags);
int				ft_p(va_list args, int *res, flag_list *flags);
int				ft_string(va_list args, int *res, flag_list *flags);
char			*ft_itoa_int(int n);
char			*ft_itoa_unsint(unsigned int n);
char			*ft_itoa_x(unsigned int n, char letter);
void			fill_table(unsigned int n, char *tab, int size, char letter);
char			*ft_putadd(void *add);
char			*ft_strdup_pf(const char *s, unsigned int start,
								unsigned int stop);
char 			*ft_strdup(const char *s);
void	 		ft_putstr(char *s);
size_t			ft_strlen(const char *str);
unsigned int	ft_atoi_printf(const char *str, unsigned int *pos,
								flag_list *flags);
void			ft_width(flag_list *flags, va_list args);
void			ft_length(flag_list *flags, va_list args);
void			flag_parsing_help(flag_list *flags, char *str,
								unsigned int *index);
int				flag_parsing(flag_list *flags, char *str, unsigned int *pos,
								va_list args);
void			ft_int_left(char *s, char *tmp, unsigned int width,
								unsigned int length);
void			ft_int_left_np(char *s, char *tmp, unsigned int width,
								unsigned int length);
void			ft_int_right(char *s, char *tmp, unsigned int width,
								unsigned int length);
void			ft_int_right_0(char *s, char *tmp, unsigned int width,
								unsigned int length);
void			display_int(char *tmp1, int *res, char *tmp);
int				manage_precision_0(flag_list *flags, char *tmp);
void			int_format(flag_list *flags, char *tmp, unsigned int *width,
								unsigned int *length);
char			*create_int(char *tmp, flag_list *flags, unsigned int width,
								unsigned int length);
void			ft_char_right(char car, char *c, unsigned int width, int mod);
void			ft_char_left(char car, char *c, unsigned int width);
void			ft_string_left(char *s, char *tmp, unsigned int width,
								unsigned int length);
void			ft_string_right(char *s, char *tmp, unsigned int width,
								unsigned int length);
int				is_a_type(char c);
void			flag_init(flag_list *flags);

#endif
