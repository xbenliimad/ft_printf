/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:32:16 by ibenli            #+#    #+#             */
/*   Updated: 2022/11/12 17:28:02 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	n_c;

	n_c = 0;
	if (n > 9)
	{
		n_c += ft_putnbr_unsigned(n / 10);
		n_c += ft_putnbr_unsigned(n % 10);
	}
	else if (n >= 0 && n <= 9)
		n_c += ft_putchar(n + '0');
	return (n_c);
}
