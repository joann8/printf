/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:34:43 by jacher            #+#    #+#             */
/*   Updated: 2020/12/03 15:01:31 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct a_list
{
	char c_init;
	void (*f)(va_list, char **);
}				arg_list;

int		ft_printf(const char *input, ...);
void	ft_percent(va_list args, char **res);
void	ft_char(va_list args, char **res);
void	ft_int(va_list args, char **res);
void	ft_unsint(va_list args, char **res);
void	ft_x(va_list args, char **res);
void	ft_X(va_list args, char **res);
void	ft_p(va_list args, char **res);
char	*ft_itoa_int(int n);
char	*ft_itoa_unsint(unsigned int n);
char	*ft_itoa_x(unsigned int n, char letter);
char	*ft_putadd(void *add);
void	ft_string(va_list args, char **res);
char	*ft_strjoin_printf(char *s1, char *s2);
void	cpy_join(char *src, char *str, unsigned int l, unsigned int st);
char	*ft_strdup_pf(const char *s, unsigned int start, unsigned int stop);
char 	*ft_strdup(const char *s);
void 	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
