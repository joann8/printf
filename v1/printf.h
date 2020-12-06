/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:34:43 by jacher            #+#    #+#             */
/*   Updated: 2020/12/06 12:12:40 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct f_list
{
	int				b_flag_minus;
	int				b_flag_zero;
	unsigned int	v_width;
	int				b_precision;
	unsigned int	v_length;
	int				b_star_length;
	int				b_star_width;
}				flag_list;

typedef struct a_list
{
	char c_init;
	void (*f)(va_list, char **, flag_list*);
}				arg_list;

int				ft_printf(const char *input, ...);
void			ft_percent(va_list args, char **res, flag_list *flags);
void			ft_char(va_list args, char **res, flag_list *flags);
void			ft_int(va_list args, char **res, flag_list *flags);
void			ft_unsint(va_list args, char **res, flag_list *flags);
void			ft_x(va_list args, char **res, flag_list *flags);
void			ft_X(va_list args, char **res, flag_list *flags);
void			ft_p(va_list args, char **res, flag_list *flags);
void			ft_string(va_list args, char **res, flag_list *flags);
char			*ft_itoa_int(int n);
char			*ft_itoa_unsint(unsigned int n);
char			*ft_itoa_x(unsigned int n, char letter);
char			*ft_putadd(void *add);
char			*ft_strjoin_printf(char *s1, char *s2);
void			cpy_join(char *src, char *str, unsigned int l, unsigned int st);
char			*ft_strdup_pf(const char *s, unsigned int start, unsigned int stop);
char 			*ft_strdup(const char *s);
void	 		ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *str);
unsigned int	ft_atoi_printf(const char *str, unsigned int *pos);
void			print_flags(flag_list flags);
unsigned int	ft_width(flag_list *flags, va_list args);
unsigned int	ft_length(flag_list *flags, va_list args);
void			ft_int_left(char *s, char *tmp, unsigned int width);
void			ft_int_right(char *s, char *tmp, unsigned int width, char c);



#endif
