/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:10:03 by fiselann          #+#    #+#             */
/*   Updated: 2022/03/24 10:40:33 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_putchar(char c);
char	*get_next_line(int fd);
char	*strjoin(char *buffer, char *data);
int		is_eol(char *data);
char	*get_line(char *str);
char	*read_file(int fd, char *buffer);
char	*update_buffer(char *str, char *substr);

#endif
