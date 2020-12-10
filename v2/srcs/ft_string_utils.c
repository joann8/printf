/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:21 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 13:20:31 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void			ft_string_left(char *s, char *tmp, unsigned int width,
								unsigned int length)
{
	unsigned int i;

	i = 0;
	while (s[i] && i < length)
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

void			ft_string_right(char *s, char *tmp, unsigned int width,
									unsigned int length)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	tmp[width] = '\0';
	while (length + i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	while (i + ft_strlen(s) < width)
	{
		tmp[i] = ' ';
		i++;
	}
	j = 0;
	while (s[j] && j < length && j < width)
	{
		tmp[i + j] = s[j];
		j++;
	}
}
