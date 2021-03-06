/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/12 22:15:45 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void			ft_add_right(char *tmp, unsigned int width)
{
	unsigned int i;

	i = 0;
	while (i < width - ft_strlen(tmp))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr(tmp);
}

void			ft_add_left(char *tmp, unsigned int width)
{
	unsigned int i;

	i = 0;
	ft_putstr(tmp);
	i = ft_strlen(tmp);
	while (i < width)
	{
		write(1, " ", 1);
		i++;
	}
}

int				ft_p(va_list args, int *res, t_flag *flags)
{
	void			*ptr;
	char			*tmp;
	unsigned int	width;

	ptr = va_arg(args, void*);
	if ((tmp = ft_putadd(ptr, flags)) == NULL)
		return (-1);
	width = ft_strlen(tmp);
	if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	*res += width;
	if (flags->b_flag_minus == 0)
		ft_add_right(tmp, width);
	else
		ft_add_left(tmp, width);
	free(tmp);
	return (1);
}
