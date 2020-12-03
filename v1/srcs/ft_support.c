/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/03 14:56:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

void	ft_percent(va_list args, char **res)
{
	char c[2];
	char *tmp;
	
	(void)args;

	c[0] = '%';
	c[1] = '\0';
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	//write(1, &c, 1);
}

void	ft_char(va_list args, char **res)
{
	char c[2];
	char *tmp;

	c[0] = (char)va_arg(args, int);
	c[1] = '\0';
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	//write(1, &c, 1);
}

void	ft_string(va_list args, char **res)
{
	char *s;
	char *tmp;

	s = va_arg(args, char *);
	tmp = ft_strjoin_printf(*res, s);
	free(*res);
	*res = ft_strdup(tmp);
	//write(1, s, ft_strlen(s));
}

void	ft_unsint(va_list args, char **res)
{
	unsigned int	d;
	char			*tmp1;
	char			*tmp2;

	d = va_arg(args, unsigned int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_unsint(d);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_int(va_list args, char **res)
{
	int				d;
	char			*tmp1;
	char			*tmp2;

	d = va_arg(args, int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_int(d);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_x(va_list args, char **res)
{
	unsigned int	d;
	char			*tmp1;
	char			*tmp2;

	d = va_arg(args, unsigned int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_x(d, 'x');
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_X(va_list args, char **res)
{
	unsigned int	d;
	char			*tmp1;
	char			*tmp2;

	d = va_arg(args, unsigned int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_x(d, 'X');
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_p(va_list args, char **res)
{
	void			*ptr;
	char			*tmp1;
	char			*tmp2;

	ptr = va_arg(args, void*);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_putadd(ptr);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}
