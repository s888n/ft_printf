/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:50:24 by srachdi           #+#    #+#             */
/*   Updated: 2022/11/15 13:27:40 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	printchar(char c, int *len);
void	printstr(char *s, int *len);
void	printnbr(int n, int *len);
void	printaddr(size_t Addr, int *len);
void	printuns(unsigned int n, int *len);
void	printhex(unsigned int num, int *len, char *base);
void	typecheck(const char *s, va_list argList, int *len);
int		ft_printf(const char *s, ...);
#endif
