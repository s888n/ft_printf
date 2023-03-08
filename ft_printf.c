/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:22:03 by srachdi           #+#    #+#             */
/*   Updated: 2022/11/15 13:27:09 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	typecheck(const char *s, va_list argslist, int *len)
{
	if (*s == 'c')
		printchar(va_arg(argslist, int), len);
	else if (*s == 's')
		printstr(va_arg(argslist, char *), len);
	else if (*s == 'p')
	{
		printstr("0x", len);
		printaddr(va_arg(argslist, size_t), len);
	}
	else if (*s == 'd')
		printnbr(va_arg(argslist, int), len);
	else if (*s == 'i')
		printnbr(va_arg(argslist, int), len);
	else if (*s == 'u')
		printuns(va_arg(argslist, unsigned int), len);
	else if (*s == 'x')
		printhex(va_arg(argslist, unsigned int), len, "0123456789abcdef");
	else if (*s == 'X')
		printhex(va_arg(argslist, unsigned int), len, "0123456789ABCDEF");
	else if (*s == '%')
	{
		printchar('%', len);
	}
	else
		printchar(*s, len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	argslist;

	len = 0;
	va_start(argslist, s);
	if (*s)
	{
		while (*s)
		{
			if (*s == '%')
			{
				s++;
				typecheck(s, argslist, &len);
			}
			else
				printchar(*s, &len);
			s++;
		}
	}
	va_end(argslist);
	return (len);
}
