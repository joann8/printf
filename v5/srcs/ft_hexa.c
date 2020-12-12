/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/12 21:03:26 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

int		ft_x(va_list args, int *res, t_flag *flags)
{
	unsigned int	d;
	char			*tmp;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	if ((tmp = ft_itoa_x(d, 'x')) == NULL)
		return (-1);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if (manage_precision_0(flags, tmp) == 1)
			return (1);
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	int_format(flags, &width, &length);
	*res += width;
	if (flags->b_flag_minus == 1)
		create_int_minus(tmp, flags, width, length);
	else
		create_int_right(tmp, flags, width, length);
	free(tmp);
	return (1);
}

int		ft_bigx(va_list args, int *res, t_flag *flags)
{
	unsigned int	d;
	char			*tmp;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	if ((tmp = ft_itoa_x(d, 'X')) == NULL)
		return (-1);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if (manage_precision_0(flags, tmp) == 1)
			return (1);
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	int_format(flags, &width, &length);
	*res += width;
	if (flags->b_flag_minus == 1)
		create_int_minus(tmp, flags, width, length);
	else
		create_int_right(tmp, flags, width, length);
	free(tmp);
	return (1);
}
