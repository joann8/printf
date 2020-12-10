/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:50:18 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 13:54:04 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void	fill_table_hexa(unsigned long n, char *tab, int size, flag_list *flags)
{
	char			*base;
	unsigned int	i;

	if (n == 0)
	{
		if (flags->b_precision == 0)
			tab[2] = '0';
		if (flags->b_precision == 1)
			tab[2] = '\0';
		return ;
	}
	base = "0123456789abcdef";
	i = 16;
	while (n > 0)
	{
		tab[size - 1] = base[n % i];
		n = n / i;
		size--;
	}
}

void	manage_neg_hexa(long n, unsigned long *nb)
{
	if (n < 0)
		*nb = -n;
	else
		*nb = n;
}

char	*ft_putadd(void *add, flag_list *flags)
{
	long			n;
	unsigned long	nb;
	unsigned int	size;
	char			*tab;

	n = (long)add;
	manage_neg_hexa(n, &nb);
	size = 2;
	if (n == 0)
		size++;
	while (nb > 0)
	{
		size++;
		nb = nb / 16;
	}
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	tab[0] = '0';
	tab[1] = 'x';
	manage_neg_hexa(n, &nb);
	fill_table_hexa(nb, tab, size, flags);
	return (tab);
}
