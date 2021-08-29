#include "bsq.h"

t_map	*g_map;
t_point	*g_point;

int	main(int argc, char **argv)
{
	int i = 1;
	g_map = (t_map *)malloc(sizeof(t_map));
	g_point = (t_point *)malloc(sizeof(t_point));
	if (g_map == NULL)
	{
		return 0;
	}
	if (argc == 1 && read_file(argc, argv[0]) == 0)
	{
		ft_puterror();
		return (0);
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			if (read_file(argc, argv[i]) == 0)
			{
				ft_puterror();
				break ;
			}
			i++;
		}
	}
	free(g_map);
	free(g_point);
	return (0);
}
