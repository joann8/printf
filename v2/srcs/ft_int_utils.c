/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 18:47:44 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		manage_negative(char *s, char *tmp, unsigned int *dif,
								unsigned int *i)
{
	if (s[0] == '-')
	{
		*dif = 1;
		tmp[*i] = '-';
		*i += 1;
	}
}

void		ft_int_left_np(char *s, char *tmp, unsigned int width,
							unsigned int length)
{
	unsigned int i;

	(void)length;
	i = 0;
	while (s[i] && (i < width))
	{
		tmp[i] = s[i];
		i++;
	}
	while (i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

void		ft_int_left(char *s, char *tmp, unsigned int width,
							unsigned int length)
{
	unsigned int i;
	unsigned int j;
	unsigned int dif;

	i = 0;
	dif = 0;
	manage_negative(s, tmp, &dif, &i);
	while (i - dif < length - ft_strlen(s))
	{
		tmp[i] = '0';
		i++;
	}
	j = 0;
	while (s[j + dif] && j < ft_strlen(s))
	{
		tmp[i] = s[j + dif];
		i++;
		j++;
	}
	while (i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

void		ft_int_right(char *s, char *tmp, unsigned int width,
							unsigned int length)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dif;

	i = 0;
	dif = 0;
	while (i < width - length)
	{
		tmp[i] = ' ';
		i++;
	}
	manage_negative(s, tmp, &dif, &i);
	j = 0;
	while (j++ < length - ft_strlen(s))
	{
		tmp[i] = '0';
		i++;
	//	j++;
	}
	j = 0;
	while (s[j + dif] && (i + j < length || i + j < width))
	{
		tmp[i + j] = s[j + dif];
		j++;
	}
	tmp[i + j] = '\0';
}

void		ft_int_right_0(char *s, char *tmp, unsigned int width,
							unsigned int length)
{
	unsigned int i;
	unsigned int j;
	unsigned int dif;

	i = 0;
	dif = 0;
	manage_negative(s, tmp, &dif, &i);
	j = 0;
	while (j < length - ft_strlen(s))
	{
		tmp[i] = '0';
		i++;
		j++;
	}
	j = 0;
	while (s[j + dif] && (i < length || i < width))
	{
		tmp[i] = s[j + dif];
		i++;
		j++;
	}
	tmp[i] = '\0';
}
