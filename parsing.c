/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:06:01 by lmenigau          #+#    #+#             */
/*   Updated: 2017/02/03 15:08:53 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_file(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	return(fd);
}

int		count_word(char *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] != c)
			i++;
		wc++;
	}
	return (wc);
}

int		*parse_number(char *s)
{
	int		count;
	int		*tab;
	int		i;
	int		j;

	count = count_word(s, ' ') + 1;
	if ((tab = malloc(sizeof (*tab) * count )) == NULL)
			return (NULL);
	tab[0] = count;
	i = 1;
	j = 0;
	while (i < count)
	{
		while(s[j] && s[j] == ' ')
			j++;
		tab[i] = ft_atoi(&s[j]);
		while (s[j] && s[j] != ' ')
			j++;
		i++;
	}
	return (tab);
}

int		load_file(t_gstate *gstate, int fd)
{
	int		ret;
	int		line_count;
	char	*line;
	t_list	*head;
	t_list	*current;

	gstate->head = malloc(sizeof (*head));
	current = gstate->head;
	line_count = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		current->content = parse_number(line);
		current->next = malloc(sizeof (*current));
		current = current->next;
		line_count++;
		free(line);
	}
	current->next = NULL;
	if (ret == -1)
		return (0);
	return(line_count);
}

int		**flaten_list(t_list *head, int list_lenght)
{
	int		**map;
	int		i;

	if ((map = malloc(sizeof(*map) * list_lenght)) == NULL)
			return (NULL);
	i = 0;
	while (i < list_lenght)
	{
		map[i] = head->content;
		head = head->next;
		i++;
	}
	return (map);
}
