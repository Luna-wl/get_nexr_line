#include "get_next_line.h"

int	main()
{
	int	fd;
	char	*str;
	int i;

	fd = open("41_with_nl", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// printf("s1 = %s\n", str);
	// printf("s1 = %s\n", str);
	str = get_next_line(fd);
	i = 1;
	while (str && i <= 10)
	{
		printf("line%d: %s", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	// printf("line = %s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("line1 = %s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("line2 = %s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("line3 = %s", str);
	// free(str);
}