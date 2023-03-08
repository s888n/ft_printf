/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strFuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:49:21 by srachdi           #+#    #+#             */
/*   Updated: 2022/11/15 11:55:45 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	printstr(char *s, int *len)
{
	if (!s)
	{
		printstr("(null)", len);
		return ;
	}
	while (*s)
	{
		printchar(*s, len);
		s++;
	}
}
