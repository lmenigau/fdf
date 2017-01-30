/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:18:19 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/30 19:01:29 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}


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

void	print_map(int	**map, int line_count)
{
	int		i;
	int		j;

	i = 0;
	while (i < line_count)
	{
		j = 0;
		while(j < map[i][0])
		{
			printf("%3d", map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	variousttest(int (*imgmem)[1000]);
int		main(int argc, char **argv)
{
	t_gstate gstate;

	int		fd;
	int		line_count;
	int		**map;
	fd = -1;
	gstate.mlx_ptr = mlx_init();
	gstate.window = mlx_new_window(gstate.mlx_ptr, 1920, 1080, "fdf");
	mlx_key_hook(gstate.window, key_hook, NULL);
	gstate.img_ptr = mlx_new_image(gstate.mlx_ptr, 1000, 1000);
	gstate.imgmem = (int (*)[1000])mlx_get_data_addr(gstate.img_ptr, &gstate.bits_per_pixel, &gstate.size_line, &gstate.endian);
	if ((fd = open_file(argc, argv)) == -1)
		return (0);;
	line_count = load_file(&gstate, fd);
	map = flaten_list(gstate.head, line_count);
	print_map(map, line_count);
	return (0);
	variousttest(gstate.imgmem);
	mlx_put_image_to_window(gstate.mlx_ptr, gstate.window, gstate.img_ptr,0, 0);
	mlx_mouse_hook(gstate.window, mouse_hook, NULL);
	mlx_hook(gstate.window, 6, 0, motion_hook, NULL);
	mlx_loop(gstate.mlx_ptr);
	return (0);
}
