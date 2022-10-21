
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

