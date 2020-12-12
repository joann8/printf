/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 15:22:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void	display_percent(char car, unsigned int size, t_flag *flags, char *c)
{
	if (flags->b_flag_minus == 0)
	{
		if (flags->b_flag_zero == 1)
			ft_char_right(car, c, size, 0);
		else
			ft_char_right(car, c, size, 1);
	}
	else
		ft_char_left(car, c, size);
}

int		ft_percent(va_list args, int *res, t_flag *flags)
{
	char			car;
	char			*c;
	unsigned int	size;

	(void)args;
	size = 1;
	if (flags->b_precision == 1)
		return ((*res = -1));
	if (flags->b_width == 1 && flags->v_width > 1)
		size = flags->v_width;
	if (!(c = malloc(sizeof(char) * (size + 1))))
		return ((*res = -1));
	car = '%';
	display_percent(car, size, flags, c);
	ft_putstr(c);
	*res += ft_strlen(c);
	free(c);
	return (1);
}
