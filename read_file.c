#include "bsq.h"

int	read_file(int argc, char *map_file)
{
	// TODO: maybe write stdin in file 'tmp' and read it after
	if (argc == 1)
		get_map_stdin();
	else
		get_map(map_file);
	if (ft_check_map() == 0)
		return (0);
	create_int_map();
	calculate_square();
	print_result();
	return (1);
}

void	get_map(char *map_file)
{
	int	fd;
	int	rd;
	int	i = 0;
	char	first_line[25];
	char	buff;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		return ;
	rd = read(fd, &first_line[i], 1);
	while (rd && first_line[i] != '\n')
	{
		i++;
		rd = read(fd, &first_line[i], 1);
	}
	first_line[i] = '\0';
	get_info_map(first_line);
	i = 0;
	rd = read(fd, &buff, 1);
	while (rd && buff != '\n')
	{
		i++;
		rd = read(fd, &buff, 1);
	}
	close(fd);
	g_map->x_size = i;
	save_map(map_file);
}

void	save_map(char *map)
{
	int	op;
	int	rd;
	char	c;
	int	x;
	int	y;

	op = open(map, O_RDONLY);
	while ((rd = read(op, &c, 1)) && c != '\n')		// skip first line
		;
	g_map->char_map = (char **)malloc(sizeof(char *) * (g_map->y_size));
	for (int i = 0; i < g_map->y_size; i++)
	{
		g_map->char_map[i] = (char *)malloc(g_map->x_size + 1);
		g_map->char_map[i][g_map->x_size] ='\0';
	}
	y = 0;
	rd = read(op, &c, 1);
	while (y < g_map->y_size)
	{
		x = 0;
		while (c != '\n')
		{
			g_map->char_map[y][x] = c;
			rd = read(op, &c, 1);
			x++;
		}
		rd = read(op, &c, 1);
		y++;
	}
	close(op);
}

void	get_map_stdin(void)
{
	int		i = 0;
	int		j = 0;
	char	first_line[25];
	int		rd;
	char	buff[FIRST_MAPLINE_SIZE];
	int		first = 1;
	while ((rd = read(0, &first_line[i], 1)) && first_line[i] != '\n')
	{
		i++;
	}
	first_line[i] = '\0';
	get_info_map(first_line);
	g_map->char_map = (char **) malloc(sizeof(char *) * g_map->y_size);
	i = 0;
	while (i < g_map->y_size)
	{
		j = 0;
		rd = read(0, &buff[j], 1);
		while (rd && buff[j] != '\n')
		{
			j++;
			rd = read(0, &buff[j], 1);
		}
		if (first == 1)
		{
			first = 0;
			g_map->x_size = j - 1;
		}
		buff[j - 1] = '\0';
		g_map->char_map[i] = ft_strdup(buff);
		i++;
	}
}

void	get_info_map(char *buff)
{
	// TODO: get num characters as empty, full, obstacle
	int	i = 0;
	int	l = 0;
	char	number[14];

	while (buff[i] != '\0')
	{
		if (buff[i] >= '0' && buff[i] <= '9')
		{
			number[l] = buff[i];
			l++;
		}
		else
		{
			number[l] = '\0';
			g_map->empty = buff[i];
			g_map->obstacle = buff[i + 1];
			g_map->full = buff[i + 2];
			g_map->y_size = ft_atoi(number);
			return ;
		}
		i++;
	}
}

void	create_int_map(void)
{
	int **matrix;
	int x = 0;
	int y = 0;

	matrix = ft_alloc_2d_array(g_map->x_size, g_map->y_size);
	if (matrix == NULL)
		return;
	while (y < g_map->y_size)
	{
		x = 0;
		while (x < g_map->x_size)
		{
			if (g_map->char_map[y][x] == g_map->empty)
				matrix[y][x] = 1;
			else if (g_map->char_map[y][x] == g_map->obstacle)
				matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	g_map->int_map = matrix;
}

void	print_result(void)
{
	for (int i = g_point->y_pos; i < g_point->y_pos + g_point->size; i++)
	{
		for (int j = g_point->x_pos; j < g_point->x_pos + g_point->size; j++)
			g_map->char_map[i][j] = g_map->full;
	}
	for (int y = 0; y < g_map->y_size; y++)
	{
		ft_putstr(g_map->char_map[y]);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	print_int_map(void)
{
	for (int y = 0; y < g_map->y_size; y++)
	{
		for (int x = 0; x < g_map->x_size; x++)
		{
			printf("%d", g_map->int_map[y][x]);
		}
		printf("\n");
	}
}
