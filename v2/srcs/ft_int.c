/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 19:20:40 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	display_int(char *tmp1, int *res, char *tmp)
{
	ft_putstr(tmp1);
	*res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
}

int		manage_precision_0(flag_list *flags, char *tmp)
{
	if (flags->b_width == 1)
	{
		tmp[0] = ' ';
		return (0);
	}
	else
	{
		write(1, "", 0);
		return (1);
	}
}

void	string_trunc(flag_list *flags, char *tmp, unsigned int *width, unsigned int *length)
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

char *create_string_unsint(char *tmp, flag_list * flags, unsigned int width, unsigned int length)
{
	char			*tmp1;
	unsigned int	size;

	if (length > width || (length > ft_strlen(tmp) && width > length))
		size = length;
	else
		size = width;
	if (flags->b_flag_zero == 1 && flags->b_precision == 0)
		length = width;
	if (!(tmp1 = malloc(sizeof(char) * (size + 1))))
	{
		free(tmp);
		return (NULL); //erreur
	}
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

int		ft_unsint(va_list args, int *res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;
	//unsigned int	size;

	d = va_arg(args, unsigned int);
	tmp = ft_itoa_unsint(d);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if ((manage_precision_0(flags, tmp) == 1))
			return (1);
	/*{
		if (flags->b_width == 1)
			tmp[0] = ' ';
		else
		{
			write(1, "", 0);
			return (1); // res ?
		}
	}*/
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	string_trunc(flags, tmp, &width, &length);
	/*if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	if (flags->b_precision == 1)
	{
		flags->b_flag_zero = 0;
		if (length < flags->v_length)
			length = flags->v_length;
		if (length > width)
			flags->b_flag_zero = 1;
	}*/
	if ((tmp1 = create_string_unsint(tmp,flags, width, length)) == NULL)
		return ((*res = -1));
	display_int(tmp1, res, tmp);
	return (1);
}


int		ft_int(va_list args, int *res, flag_list *flags)
{
	int				d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;
	unsigned int	size;

	d = va_arg(args, int);
	tmp = ft_itoa_int(d);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
		if ((manage_precision_0(flags, tmp) == 1))
			return (1);
	string_trunc(flags, tmp, &width, &length);
/*
		if (flags->b_width == 1)
			tmp[0] = ' ';
		else
		{
			write(1, "", 0);
			return (1);
		}
	}*/
/*
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	if (flags->b_precision == 1)
	{
		flags->b_flag_zero = 0;
		if (length < flags->v_length)
			length = flags->v_length;
		if (length > width)
			flags->b_flag_zero = 1;
	}*/
	if (length > width || (length > ft_strlen(tmp) && width > length))
	{
		if (d < 0)
			length++;
		size = length;
	}
	else
		size = width;
	if (flags->b_flag_zero == 1 && flags->b_precision == 0)
		length = width;
	if (!(tmp1 = malloc(sizeof(char) * (size + 1))))
	{
		free(tmp);
		return ((*res = -1)); //erreur
	}
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
	display_int(tmp1, res, tmp);
	return (1);
}
