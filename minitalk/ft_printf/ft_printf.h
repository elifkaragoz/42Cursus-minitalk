/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaragoz <ekaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:46:55 by ekaragoz          #+#    #+#             */
/*   Updated: 2023/07/20 15:46:58 by ekaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long ptr);
int	ft_putnbr(int nbr);
int	ft_putnbr_u(unsigned int nbr);
int	ft_puthex(unsigned int nbr, char *base);
int	ft_flags_manager(va_list vl, const char flag);
int	ft_printf(const char *format, ...);

#endif
