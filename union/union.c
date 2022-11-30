/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:46:56 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/30 11:06:00 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strchr(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main (int argc, char **argv)
{
	int i;
	int len;

	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		i = 0;
		while (argv[1][i])	
		{
			if (ft_strchr(argv[1], argv[1][i], i) == 1)
				ft_putchar(argv[1][i]);
			i++;
		}
		len = i;
		i = 0;
		while (argv[2][i])
		{
			if (ft_strchr(argv[1], argv[2][i], len) == 0)
			{
		  		i++;
				continue ;
			}		
			if (ft_strchr(argv[2], argv[2][i], i) == 1)
				ft_putchar(argv[2][i]);
			i++;
		}
		write(1, "\n", 1);
	}	
	return (0);
}
