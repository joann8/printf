/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/05 21:49:18 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>


void	ft_unsint(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp1;
	char			*tmp2;

	(void)flags;

	d = va_arg(args, unsigned int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_unsint(d);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_int(va_list args, char **res, flag_list *flags)
{
	int				d;
	char			*tmp1;
	char			*tmp2;

	(void)flags;

	d = va_arg(args, int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_int(d);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_x(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp1;
	char			*tmp2;

	(void)flags;

	d = va_arg(args, unsigned int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_x(d, 'x');
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_X(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp1;
	char			*tmp2;

	(void)flags;
	
	d = va_arg(args, unsigned int);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_itoa_x(d, 'X');
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_p(va_list args, char **res, flag_list *flags)
{
	void			*ptr;
	char			*tmp1;
	char			*tmp2;

	(void)flags;

	ptr = va_arg(args, void*);
	//ft_putnbr_fd(d, 1);
	tmp1 = ft_putadd(ptr);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}
