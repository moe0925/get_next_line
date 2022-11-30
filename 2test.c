int get_next_line(int fd, char **line)
{
	int read_byte;
	char *memo;
	int BUFFER_SIZE;
	int i;
	static char *save;
	save = malloc (sizeof(char) * 1);
	save[0] = 0;
	BUFFER_SIZE = 5;
	char *line2;
	line2 = *line;
	char *temp;
	int j;
	j = 0;
	

	memo = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!memo)
		return (0);
	
	read_byte = read(fd,memo, BUFFER_SIZE);
	i = 0;

	if (read_byte < 0)
		return (0);

	while (read_byte > 0)
	{
		memo[BUFFER_SIZE + 1] = 0;
		char *find;
	
		find = ft_strchr(memo, '\n');
		if (save == 0)
			save = &memo[0];
		printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト１〜〜〜〜〜〜〜〜〜\n%s\n",save);

		while(ft_strchr(memo,'\n') != 0)
		{
			*find = 0;

			j++;
			printf("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜%d回目の改行発見~~~~~~~~~~\n",j);
			// printf("%s\n",save);
			// printf("%s\n",memo);

			line2 = (char *)malloc((sizeof(char))*((ft_strlen(save)) + (ft_strlen(memo)) + 1));
			line2 = ft_strjoin(save,memo);
			// printf ("%s",ft_strjoin(save,memo));
			printf ("%s\n",line2);
			save[0] = 0;
			memo = find +1 ;
			printf("現時点でのsave");
			printf("%s\n", save);
			printf("line: %s\n",line2);


		}
		// save = find + 1;
		printf ("〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜テスト2〜〜〜〜〜〜〜〜〜\n%s\n",save);

		
		if (ft_strchr(memo,'\n')== 0)
		{
		printf("~~~~~~~~~~~~~~~~~~~~~改行なし~~~~~~~~~~\n");

		// if (*save == 0 )
		// 	save = &memo[0];
		
		temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		temp = memo;
		save = ft_strjoin(save,temp);
		temp = 0;
		
		// printf ("%s\n",memo);
		printf ("変更後%s\n",save);

		// printf ("%p",save);
		// for (int i = 0; i < BUFFER_SIZE ; i++)
		i++;
		printf("%d回目\n",i);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf ("最後%s\n",save);




		}
		

		read_byte = read(fd,memo, BUFFER_SIZE);
		// printf("~~~~~~~~~~~~再読み込み~~~~~~~~~~~~~~~~~~~\n");




	}
	
	
	if (read_byte == 0)
		printf("%s\n",save);	
	printf ("000\n");
	return (0);

	return (0);
}







int  BUFFER_SIZE = 1000;

int main(void)
{
 int  fd;
 char *line;
 int  check;

 line = "";
 fd = 1000;
 //open("text.txt", O_RDONLY);
 check = 1;
 while (line)
 {
  line = get_next_line(fd);
  printf("> %s", line);
  check++;
  free(line);
 }
 system("leaks a.out");
 return (0);
}