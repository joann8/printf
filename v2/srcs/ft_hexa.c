/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 13:52:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

int		ft_x(va_list args, int *res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'x');
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if (manage_precision_0(flags, tmp) == 1)
			return (1);
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	int_format(flags, tmp, &width, &length);
	if ((tmp1 = create_int(tmp, flags, width, length)) == NULL)
	{
		free(tmp);
		return ((*res = -1));
	}
	display_int(tmp1, res, tmp);
	return (1);
}

int		ft_bigx(va_list args, int *res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'X');
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if (manage_precision_0(flags, tmp) == 1)
			return (1);
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	int_format(flags, tmp, &width, &length);
	if ((tmp1 = create_int(tmp, flags, width, length)) == NULL)
	{
		free(tmp);
		return ((*res = -1));
	}
	display_int(tmp1, res, tmp);
	return (1);
}
