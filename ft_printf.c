/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:32:24 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/12 15:32:58 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_printf(char c, va_list ptr)
{
	int	n_c;

	n_c = 0;
	if (c == '%')
		n_c += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		n_c += ft_putnbr(va_arg(ptr, int));
	else if (c == 'c')
		n_c += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		n_c += ft_putstr(va_arg(ptr, char *));
	else if (c == 'u')
		n_c += ft_putnbr_unsigned(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		n_c += ft_puthexa(c, va_arg(ptr, unsigned int));
	else if (c == 'p')
		n_c += ft_putadress('x', va_arg(ptr, unsigned long));
	else
		n_c += ft_putchar(c);
	return (n_c);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	size_t		n_c;
	va_list		ptr_arg;
	
	if (!str)
		return (-1);
	va_start(ptr_arg, str);
	i = 0;
	n_c = 0;
	while (str[i])
	{
		if (str[i] == '%')
			n_c += ft_handle_printf(str[++i], ptr_arg);
		else
			n_c += ft_putchar(str[i]);
		i++;
	}		
	va_end(ptr_arg);
	return (n_c);
}
