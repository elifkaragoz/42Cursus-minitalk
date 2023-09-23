/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaragoz <ekaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:27:10 by ekaragoz          #+#    #+#             */
/*   Updated: 2023/07/20 15:27:15 by ekaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptrlen(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static void	ft_putptr_helper(unsigned long ptr, char *hex)
{
	if (ptr < 16)
	{
		ft_putchar(hex[ptr % 16]);
	}
	else
	{
		ft_putptr_helper(ptr / 16, hex);
		ft_putchar(hex[ptr % 16]);
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	if (ptr == 0)
		counter += write(1, "0", 1);
	else
	{
		ft_putptr_helper(ptr, "0123456789abcdef");
		counter += ptrlen(ptr);
	}
	return (counter);
}
