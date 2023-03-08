/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrFuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:45:53 by srachdi           #+#    #+#             */
/*   Updated: 2022/11/15 13:32:09 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnbr(int n, int *len)
{
	if (n == -2147483648)
		printstr("-2147483648", len);
	else if (n < 0)
	{
		printchar('-', len);
		n *= -1;
		printnbr(n, len);
	}
	else if (n > 9)
	{
		printnbr(n / 10, len);
		printnbr(n % 10, len);
	}
	else
		printchar(n + 48, len);
}

void	printaddr(size_t addr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (addr >= 16)
		printaddr(addr / 16, len);
	addr = addr % 16;
	printchar(base[addr % 16], len);
}

void	printuns(unsigned int n, int *len)
{
	if (n > 9)
	{
		printuns(n / 10, len);
		printuns(n % 10, len);
	}
	else
		printchar(n + 48, len);
}

void	printhex(unsigned int num, int *len, char *base)
{
	if (num >= 16)
		printhex(num / 16, len, base);
	num = num % 16;
	printchar(base[num % 16], len);
}
