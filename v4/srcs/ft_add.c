/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 19:27:00 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void			ft_add_right(char *tmp, char *tmp1, unsigned int width)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	tmp1[width] = '\0';
	while (i < width - ft_strlen(tmp))
	{
		tmp1[i] = ' ';
		i++;
	}
	j = 0;
	while (tmp[j] && i + j < width)
	{
		tmp1[i + j] = tmp[j];
		j++;
	}
}

void			ft_add_left(char *tmp, char *tmp1, unsigned int width)
{
	unsigned int i;

	i = 0;
	tmp1[width] = '\0';
	while ((tmp[i]) && i < width)
	{
		tmp1[i] = tmp[i];
		i++;
	}
	while (i < width)
	{
		tmp1[i] = ' ';
		i++;
	}
}

void			display_add(char *tmp1, int *res, char *tmp)
{
	ft_putstr(tmp1);
	*res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
}

int				ft_p(va_list args, int *res, t_flag *flags)
{
	void			*ptr;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;

	if (flags->b_flag_zero == 1)
		return ((*res = -1));
	ptr = va_arg(args, void*);
	if ((tmp = ft_putadd(ptr, flags)) == NULL)
		return (-1);
	width = ft_strlen(tmp);
	if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(tmp);
		return ((*res = -1));
	}
	if (flags->b_flag_minus == 0)
		ft_add_right(tmp, tmp1, width);
	else
		ft_add_left(tmp, tmp1, width);
	display_add(tmp1, res, tmp);
	return (1);
}