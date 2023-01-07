/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rapgonca < rapgonca@student.42sp.org.b    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:43:41 by  rapgonca         #+#    #+#             */
/*   Updated: 2022/10/04 20:28:27 by  rapgonca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(int fd, char *nl_temp)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(nl_temp, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		nl_temp = ft_strjoin_gnl(nl_temp, buffer);
	}
	free (buffer);
	return (nl_temp);
}

char	*save_line(char *temp)
{
	int		n;
	char	*newline;

	n = 0;
	if (!temp[n])
		return (NULL);
	while (temp[n] != '\n' && temp[n])
		n++;
	if (!temp[n])
		n--;
	newline = (char *)malloc((n + 2) * sizeof(char));
	if (!newline)
		return (NULL);
	n = 0;
	while (temp[n] != '\n' && temp[n])
	{
		newline[n] = temp[n];
		n++;
	}
	if (temp[n] == '\n')
		newline[n++] = '\n';
	newline[n] = '\0';
	return (newline);
}

char	*clean_line(char *tmp)
{
	int		count;
	int		i;
	char	*newtmp;

	count = 0;
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	newtmp = (char *)malloc((ft_strlen(tmp) - i + 1) * sizeof(char));
	if (!newtmp)
		return (NULL);
	i++;
	while (tmp[i])
		newtmp[count++] = tmp[i++];
	newtmp[count++] = '\0';
	free(tmp);
	return (newtmp);
}

char	*get_next_line(int fd)
{
	char		*nl;
	static char	*nl_temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl_temp = read_buf(fd, nl_temp);
	if (!nl_temp)
		return (NULL);
	nl = save_line(nl_temp);
	nl_temp = clean_line(nl_temp);
	return (nl);
}
