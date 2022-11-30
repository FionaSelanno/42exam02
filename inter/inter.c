/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:08:27 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/30 11:21:38 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strchr(char *str, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int i;
	int	j;
	int len;

	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		i = 0;
		j = 0;
		len = ft_strlen(argv[2]);
		while (argv[1][i])
		{
			if ((ft_strchr(argv[2], argv[1][i], len) == 0) && (ft_strchr(argv[1], argv[1][i], i) == 1))
			   ft_putchar(argv[1][i]);
			i++;	
		}
		write(1, "\n", 1);
	}
	return (0);
}
