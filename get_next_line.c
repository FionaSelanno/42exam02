/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:09:18 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/23 16:11:42 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*strjoin(char *buffer, char *data)
{
	char	*strjoined;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(buffer) + ft_strlen(data);
	strjoined = malloc(sizeof(char) * (len + 1));
	if (!strjoined)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer && buffer[i])
	{
		strjoined[j++] = buffer[i++];
	}
	i = 0;
	while (data[i])
		strjoined[j++] = data[i++];
	strjoined[j] = '\0';
	free(buffer);
	return (strjoined);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}	
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*data;
	int		nbytes;

	data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!data)
		return (NULL);
	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, data, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(data);
			return (NULL);
		}
		data[nbytes] = '\0';
		buffer = strjoin(buffer, data);
		if (is_eol(data) != 0)
			break ;
	}
	free(data);
	return (buffer);
}

char	*update_buffer(char *str, char *substr)
{
	char	*updated;
	int		len_str;
	int		len_substr;
	int		i;

	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	len_substr = ft_strlen(substr);
	len_str = ft_strlen(str);
	updated = malloc(sizeof(char) * (len_str - len_substr) + 1);
	if (!updated)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[len_substr])
		updated[i++] = str[len_substr++];
	updated[i] = '\0';
	free(str);
	return (updated);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer, line);
	return (line);
}

int main(void)
{
	int fd;
	char *line;

	printf("in main\n");
	fd = open("testfile.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		write(1, "RESULT:", 7);
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
}

