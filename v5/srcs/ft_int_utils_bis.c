/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 19:24:54 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void	display_int(char *tmp1, int *res, char *tmp)
{
	ft_putstr(tmp1);
	*res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
}

int		manage_precision_0(t_flag *flags, char *tmp)
{
	if (flags->b_width == 1)
	{
		tmp[0] = ' ';
		return (0);
	}
	else
	{
		write(1, "", 0);
		free(tmp);
		return (1);
	}
}

void	int_format(t_flag *flags, char *tmp, unsigned int *width,
						unsigned int *length)
{
	*width = ft_strlen(tmp);
	*length = ft_strlen(tmp);
	if (flags->b_width == 1 && *width < flags->v_width)
		*width = flags->v_width;
	if (flags->b_precision == 1)
	{
		flags->b_flag_zero = 0;
		if (*length < flags->v_length)
			*length = flags->v_length;
		if (*length > *width)
			flags->b_flag_zero = 1;
	}
}

void	change_size(unsigned int *size, char *tmp, unsigned int *width,
						unsigned int *length)
{
	if (*length > *width || (*length > ft_strlen(tmp) && *width > *length))
	{
		if (tmp[0] == '-')
			*length += 1;
		*size = *length;
	}
}

char	*create_int(char *tmp, t_flag *flags, unsigned int width,
						unsigned int length)
{
	char			*tmp1;
	unsigned int	size;

	size = width;
	change_size(&size, tmp, &width, &length);
	if (flags->b_flag_zero == 1 && flags->b_precision == 0)
		length = width;
	if (!(tmp1 = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (flags->b_flag_minus == 1)
	{
		if (flags->b_precision == 0)
			ft_int_left_np(tmp, tmp1, width, length);
		else
			ft_int_left(tmp, tmp1, width, length);
	}
	else
	{
		if (flags->b_flag_zero == 1)
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width, length);
	}
	return (tmp1);
}
