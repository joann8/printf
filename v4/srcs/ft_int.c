/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 19:23:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

int		ft_unsint(va_list args, int *res, t_flag *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	if ((tmp = ft_itoa_unsint(d)) == NULL)
		return (-1);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if ((manage_precision_0(flags, tmp) == 1))
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

int		ft_int(va_list args, int *res, t_flag *flags)
{
	int				d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, int);
	if ((tmp = ft_itoa_int(d)) == NULL)
		return (-1);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if ((manage_precision_0(flags, tmp) == 1))
			return (1);
	int_format(flags, tmp, &width, &length);
	if (((tmp1 = create_int(tmp, flags, width, length)) == NULL))
	{
		free(tmp);
		return ((*res = -1));
	}
	display_int(tmp1, res, tmp);
	return (1);
}