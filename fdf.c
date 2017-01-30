/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:18:19 by lmenigau          #+#    #+#             */
/*   Updated: 2017/01/30 17:52:35 by lmenigau         ###   ########.fr       */
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

	count = count_word(s, ' ') + 2;
	if ((tab = malloc(sizeof (*tab) * count )) == NULL)
			return (NULL);
	i = 0;
	j = 0;
	tab[0] = count;
	while (i < count)
	{
		while(s[j] && s[j] == ' ')
			j++;
		while ((s[j] && s[j] <= 0 && s[j] >= 9) || s[j] == '-')
			j++;
		tab[i] = ft_atoi(&s[j]);
		i++;
	}
	return (tab);
}

int		load_file(int fd)
{
	int		ret;
	int		line_count;
	char	*line;
	t_list	*head;
	t_list	*current;

	head = malloc(sizeof (*head));
	current = head;
	line_count = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		current->content = parse_number(line);
		current->next = malloc(sizeof (*current));
		current = current->next;
		free(line);
	}
	current->next = NULL;
	if (ret == -1)
		return (0);
	return(1);
}


void	variousttest(int (*imgmem)[1000]);
int		main(int argc, char **argv)
{
	t_gstate gstate;

	int		fd;
	fd = -1;
	gstate.mlx_ptr = mlx_init();
	gstate.window = mlx_new_window(gstate.mlx_ptr, 1920, 1080, "fdf");
	mlx_key_hook(gstate.window, key_hook, NULL);
	gstate.img_ptr = mlx_new_image(gstate.mlx_ptr, 1000, 1000);
	gstate.imgmem = (int (*)[1000])mlx_get_data_addr(gstate.img_ptr, &gstate.bits_per_pixel, &gstate.size_line, &gstate.endian);
	if ((fd = open_file(argc, argv)) == -1)
		return (0);;
	printf("%d\n", fd);
	load_file(fd);
	return (0);
	variousttest(gstate.imgmem);
	mlx_put_image_to_window(gstate.mlx_ptr, gstate.window, gstate.img_ptr,0, 0);
	mlx_mouse_hook(gstate.window, mouse_hook, NULL);
	mlx_hook(gstate.window, 6, 0, motion_hook, NULL);
	mlx_loop(gstate.mlx_ptr);
	return (0);
}
