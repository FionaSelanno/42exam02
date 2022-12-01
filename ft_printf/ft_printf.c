/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:24:57 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/30 12:58:23 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
	return (len);
}

int	ft_putnbr(long int nbr, int len)
{
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		len = ft_putnbr(nbr / 10, len);
		len = ft_putnbr(nbr % 10, len);
	}
	else
		len += ft_putchar(nbr + '0');
	return (len);
}

int	ft_puthex(unsigned long int nbr, char *base, int len)
{
	if (nbr < 0)
			nbr = -nbr;
	while (nbr >= 16)
	{
		len = ft_puthex(nbr / 16, "0123456789abcdef", len);
		nbr %= 16;
	}
	if (nbr < 16)
		len += ft_putchar(base[nbr]);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int 	len;
	va_list	buffer;

	i = 0;
	len = 0;
	va_start(buffer, str);
	while(str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				len += ft_putstr(va_arg(buffer, char *));
				i++;
			}
			else if (str[i + 1] == 'd')
			{
				len += ft_putnbr(va_arg(buffer, int), 0);
				i++;
			}
			else if (str[i + 1] == 'x')
			{
				len += ft_puthex(va_arg(buffer, unsigned int), "0123456789abcdef", 0);
				i++;
			}
			else
				len += ft_putchar('%');
		}
		i++;	
	}
	va_end(buffer);
	return (len);
}

#include <stdio.h>

/*int main(void)
{

	printf(" <- OR  value, return: %d", printf("%s", "toto"));
	printf("\n");
	printf(" <- MINE value return: %d", ft_printf("%s", "toto"));
	return (0);
}*/

/*int main(void)
{
	char *str = NULL;
	printf("\n\nTEST %%s\n\n");
	printf("\n___TEST %%s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", str));
	printf("Original - %d\n", printf("|%s|\n", str));

	printf("\n___TEST %%ss___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", str));
	printf("Original - %d\n", printf("|%ss|\n", str));

	printf("\n___TEST %%20s___\n");
	printf("No original - %d\n", ft_printf("|%20s|\n", str));
	printf("Original - %d\n", printf("|%20s|\n", str));

	printf("\n___TEST %%2s___\n");
	printf("No original - %d\n", ft_printf("|%2s|\n", str));
	printf("Original - %d\n", printf("|%2s|\n", str));

	printf("\n\nTEST %%d\n\n");
	int num = 0;
	printf("\n___TEST %%d___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", num));
	printf("Original - %d\n", printf("|%d|\n", num));

	printf("\n___TEST %%dd___\n");
	printf("No original - %d\n", ft_printf("|%dd|\n", num));
	printf("Original - %d\n", printf("|%dd|\n", num));

	printf("\n___TEST %%20d___\n");
	printf("No original - %d\n", ft_printf("|%20d|\n", num));
	printf("Original - %d\n", printf("|%20d|\n", num));

	printf("\n___TEST %%2d___\n");
	printf("No original - %d\n", ft_printf("|%2d|\n", num));
	printf("Original - %d\n", printf("|%2d|\n", num));

	printf("\n\nTEST %%x\n\n");
	unsigned int un = 0;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	printf("\n___TEST %%20x___\n");
	printf("No original - %d\n", ft_printf("|%20x|\n", un));
	printf("Original - %d\n", printf("|%20x|\n", un));

	printf("\n___TEST %%2x___\n");
	printf("No original - %d\n", ft_printf("|%2x|\n", un));
	printf("Original - %d\n", printf("|%2x|\n", un));

	return (0);
}*/
