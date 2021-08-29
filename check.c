#include "bsq.h"

int	ft_check_map(void)
{
	if (check_min() == 0 || check_chars() == 0)
	{
		return (0);
	}
	return (1);
}

int	check_min(void)
{
	if (g_map->x_size < 1 || g_map->y_size < 1)
		return (0);
	return (1);
}

int	check_chars(void)
{
	for (int y = 0; y < g_map->y_size; y++)
	{
		for (int x = 0; x < g_map->x_size; x++)
		{
			if (g_map->char_map[y][x] == g_map->full)
				return (0);
			if (g_map->char_map[y][x] != g_map->empty && g_map->char_map[y][x] != g_map->obstacle)
				return (0);
		}
	}
	return (1);
}
