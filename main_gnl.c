
int main(void)
{
	int file;
	char str[1000];

	ft_bzero(&str, 1000);
	file = open("text02.txt", O_RDONLY);
	if(file == -1)
	{
		printf("Não foi possivel abrir o arquivo.\n");
		exit(0);
	}
	while(read(file, str, BUFFER_SIZE) != 0)
	{
		printf("%s", str);
	}
	close(file);
	return(0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s && c == '\0')
		return ((char *)(s + i));
	return (0);
}
