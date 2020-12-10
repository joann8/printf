/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 11:11:42 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_add_right(char *tmp, char *tmp1, unsigned int width)
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

static void		ft_add_left(char *tmp, char *tmp1, unsigned int width)
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

static void		free_p(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

int				ft_p(va_list args, int *res, flag_list *flags)
{
	void			*ptr;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;

	if (flags->b_flag_zero == 1)
		return ((*res = -1));
	ptr = va_arg(args, void*);
	tmp = ft_putadd(ptr);
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
	ft_putstr(tmp1);
	*res = *res + ft_strlen(tmp1) + 2;
	free_p(tmp, tmp1);
	return (1);
}
