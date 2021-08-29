#include "bsq.h"

int	**ft_alloc_2d_array(int x, int y)
{
	int i = 0;
	int **arr = (int**)malloc(y * sizeof(int*));
	if (arr == NULL)
		return NULL;
	while (i < y)
	{
		arr[i] = (int*)malloc(x * sizeof(int));
		i++;
	}
	return (arr);
}
