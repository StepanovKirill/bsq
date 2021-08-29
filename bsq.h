#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#define FIRST_MAPLINE_SIZE 4096

typedef struct	s_map {
	char	**char_map;
	int	**int_map;
	char	empty;
	char	obstacle;
	char	full;
	int	x_size;
	int	y_size;
} t_map;

typedef struct s_point {
	int x_pos;
	int y_pos;
	int size;
} t_point;

t_map	*g_map;
t_point	*g_point;

// utils.c
char	*ft_strdup(char	*str);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_atoi(char *str);
void	ft_puterror(void);

// readfile.c
int	read_file(int argc, char *map_file);
void	get_map(char *map_file);
void	get_map_stdin(void);
void	get_info_map(char *buff);
void	create_int_map(void);
void	save_map(char	*map);
void	print_result(void);
void	print_int_map(void);

// search_bsq.c
int		min_three(int a, int b, int c);
void	calculate_square(void);

// malloc.c
int	**ft_alloc_2d_array(int x, int y);

// check.c
int	ft_check_map(void);
int	check_min(void);
int	check_chars(void);

#endif
