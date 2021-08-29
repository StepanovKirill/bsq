#include "bsq.h"

void calculate_square()
{
	int x = 0;
	int y = 0;

    g_point->x_pos = 0;
    g_point->y_pos = 0;
    g_point->size = 0;

    if (g_map->y_size == 1)
    {
    	while (x < g_map->x_size)
    	{
    		if (g_map->char_map[y][x] == g_map->empty)
    		{
    			g_point->size = g_map->int_map[y][x];
			    g_point->x_pos = x;
                g_point->y_pos = y;
                return;
    		}
    		x++;
    	}
    } else if (g_map->x_size == 1)
    {
    	while (y < g_map->y_size)
    	{
    		if (g_map->char_map[y][x] == g_map->empty)
    		{
    			g_point->size = g_map->int_map[y][x];
			    g_point->x_pos = x;
                g_point->y_pos = y;
                return;
    		}
    		y++;
    	}
    }
    y = g_map->y_size - 2;
	while (y >= 0)
	{
		x = g_map->x_size - 2;
		while (x >= 0)
		{
			if (g_map->int_map[y][x] > 0)
				g_map->int_map[y][x] = 1 + min_three(g_map->int_map[y][x + 1], g_map->int_map[y + 1][x + 1], g_map->int_map[y + 1][x]);
			if (g_map->int_map[y][x] >= g_point->size)
			{
			    g_point->size = g_map->int_map[y][x];
			    g_point->x_pos = x;
                g_point->y_pos = y;
			}
			x--;
		}
		y--;
	}
}

int		min_three(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else if (b < c)
		return (b);
	else
		return (c);
}
