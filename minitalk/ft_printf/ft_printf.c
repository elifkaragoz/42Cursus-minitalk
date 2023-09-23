/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaragoz <ekaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:46:50 by ekaragoz          #+#    #+#             */
/*   Updated: 2023/07/20 15:47:02 by ekaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_manager(va_list vl, const char flag)
{
	int	print_count;

	print_count = 0;
	if (flag == 'c')
		print_count += ft_putchar(va_arg(vl, int));
	else if (flag == 's')
		print_count += ft_putstr(va_arg(vl, char *));
	else if (flag == 'p')
		print_count += ft_putptr(va_arg(vl, unsigned long));
	else if (flag == 'd' || flag == 'i')
		print_count += ft_putnbr(va_arg(vl, int));
	else if (flag == 'u')
		print_count += ft_putnbr_u(va_arg(vl, unsigned int));
	else if (flag == 'x')
		print_count += ft_puthex(va_arg(vl, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		print_count += ft_puthex(va_arg(vl, unsigned int), "0123456789ABCDEF");
	else if (flag == '%')
		print_count += ft_putchar('%');
	return (print_count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_count;
	va_list	vl;

	i = 0;
	print_count = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_count += ft_flags_manager(vl, format[i]);
		}
		else
			print_count += write(1, &format[i], 1);
		i++;
	}
	va_end(vl);
	return (print_count);
}
