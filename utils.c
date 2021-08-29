#include "bsq.h"

char	*ft_strdup(char *str)
{
	int	len = ft_strlen(str);
	char	*copy = (char *)malloc(len + 1);

	for (int i = 0; str[i] != '\0'; i++)
		copy[i] = str[i];
	copy[len] = '\0';
	return (copy);
}

void	ft_putstr(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

int	ft_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	int index = 0;
	int sign = 1;
	int result = 0;

	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result * sign);
}

void	ft_puterror(void)
{
	write(2, "map error\n", 10);
}
