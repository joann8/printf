/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:34:43 by jacher            #+#    #+#             */
/*   Updated: 2020/12/13 15:54:27 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_H
# define PF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_struct
{
	int				b_flag_minus;
	int				b_flag_zero;
	int				b_width;
	unsigned int	v_width;
	int				b_star_width;
	int				b_precision;
	int				b_intneg;
	unsigned int	v_length;
	int				b_star_length;
}					t_flag;

int					ft_printf(const char *input, ...);
int					look_for_function(char c, va_list args, int *res,
										t_flag *flags);
char				*ft_strdup_pf(const char *s, unsigned int start,
									unsigned int stop);
char				*ft_strdup(const char *s);
void				ft_putstr(char *s);
size_t				ft_strlen(const char *str);
unsigned int		ft_atoi_printf(const char *str, unsigned int *pos,
									t_flag *flags, int mod);
int					ft_char(va_list args, int *res, t_flag *flags);
void				ft_char_right(char car, char *c, unsigned int width,
									int mod);
void				ft_char_left(char car, char *c, unsigned int width);
void				display_char(char car, unsigned int size, t_flag *flags,
								char *c);
void				display_c(char *c, int *res);
int					ft_p(va_list args, int *res, t_flag *flags);
void				ft_add_left(char *tmp, unsigned int width);
void				ft_add_right(char *tmp, unsigned int width);
int					is_a_type(char c);
void				flag_init(t_flag *flags);
int					ft_x(va_list args, int *res, t_flag *flags);
int					ft_bigx(va_list args, int *res, t_flag *flags);
int					ft_int(va_list args, int *res, t_flag *flags);
int					ft_unsint(va_list args, int *res, t_flag *flags);
int					manage_precision_0(t_flag *flags, char *tmp);
void				int_format(t_flag *flags, unsigned int *width,
								unsigned int *length);
void				int_minus(char *tmp, t_flag *flags, unsigned int width,
								unsigned int length);
void				int_right(char *tmp, t_flag *flag, unsigned int width,
								unsigned int length);
void				man_neg(int n, unsigned int *nbr, unsigned int *size,
								int mod);
char				*ft_itoa_int(int n);
char				*ft_itoa_unsint(unsigned int n);
char				*ft_itoa_x(unsigned int n, char letter);
void				fill_table(unsigned int n, char *tab, int size,
								char letter);
void				ft_star(t_flag *flags, va_list args);
void				flag_parsing_width(t_flag *flags, char *str,
										unsigned int *index);
void				flag_parsing_precision(t_flag *flags, char *str,
											unsigned int *index);
void				init_parsing(t_flag *flags, char *str, unsigned int *index);
int					flag_parsing(t_flag *flags, char *str, unsigned int *pos,
									va_list args);
void				display_percent(char car, unsigned int size,
									t_flag *flags, char *c);
int					ft_percent(va_list args, int *res, t_flag *flags);
void				fill_table_hexa(unsigned long n, char *tab, int size,
										t_flag *flags);
char				*ft_putadd(void *add, t_flag *flags);
int					ft_string(va_list args, int *res, t_flag *flags);
void				display_string(t_flag *flags, char *tmp_p,
										unsigned int width);
char				*string_null(int *bol);
char				*string_precision(char *s, t_flag *flags);

#endif
