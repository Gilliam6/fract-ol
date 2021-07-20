#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	int		index;
	char	*mem;

	counter = 0;
	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[counter])
		counter++;
	while (s2[index])
		index++;
	mem = (char *)malloc(counter + index + 1);
	if (!mem)
		return (0);
	counter = 0;
	while (*s1)
		mem[counter++] = *s1++;
	while (*s2)
		mem[counter++] = *s2++;
	mem[counter] = 0;
	return (mem);
}
