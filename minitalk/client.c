/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaragoz <ekaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:01:41 by ekaragoz          #+#    #+#             */
/*   Updated: 2023/09/10 17:30:04 by ekaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	ft_sendserver(int pid, char *str)
{
	int		bit;
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		bit = 8;
		c = str[i];
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_sendserver(ft_atoi(av[1]), av[2]);
	else
	{
		ft_printf("Number of incorrect arguments");
		return (1);
	}
	return (0);
}
