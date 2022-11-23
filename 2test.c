// char *make_save()
// {

// }
char *make_line(int fd ,char *save,int BUFFER_SIZE)
{

	char memo[256];
	int	flag;
	int i;
	char *line;
	i = 0;
	if (fd < 0)
		return (0);
	fd = 0;
	save = malloc (sizeof(char) * 1);
	save[0] = 0;
	read(fd,memo,BUFFER_SIZE);

	while (i < BUFFER_SIZE)// ファイルの読み込みが終わるまで？？
	{
		if (check(memo[i]) == 1)//もしバッファサイズ分ごとに探している途中に改行が発見されたら、
		{
			printf("----------------");
			memo[i] = 0;
			line = malloc (sizeof(char) * (ft_strlen(save) + i + 1));
			line = ft_strjoin(save, &memo[0]);
			printf("%s\n",save);
			save = &memo[i + 1];

			return (line);
			
			// line2 = (char *)malloc((sizeof(char)) * ((i) + 1));
			// if (!line2)
			// 	return (0);
			// printf("~~~~~~~~~~~~~~~~~~~line~~~~~~~~~~");

			// line2 = ft_strjoin(save, &memo[0]);
			// return (line2);

			// printf("%s",line2);
		}
		save = &memo[0];
		// else
		// {
		// 	save = malloc(sizeof(char) * (i + 2));
		// 	save = ft_strjoin(save, &memo[i]);
		// 	save = memo;
		// 	printf("~~~~~~~~~~~~~~save~~~~~~~~~~~~~~\n");

		// 	printf("%s\n",save);
		// }
		i++;
	}
	return (line);
}




int get_next_line(int fd, char **line)
{
	int BUFFER_SIZE;
	int	flag;
	// char memo[256];
	static char *save;
	BUFFER_SIZE = 6;

	*line = make_line(fd, save,BUFFER_SIZE);
	for (int i = 0;i<4;i++)
		printf("%c",line[0][i]);
	

	
	// while ()

	// read(fd,&memo, BUFFER_SIZE );
	// flag = read(fd,&memo,BUFFER_SIZE );
	// char *c = memo;
	// for (int i = 0;i < 6;i++)
	// printf("%s\n",&memo);
	// printf("%c\n",memo[2]);

	// printf("%d\n",flag);

	// read(fd,&memo, BUFFER_SIZE);
	// flag = read(fd,memo,BUFFER_SIZE);

	
	// while (//ファイルの読み込みが終わるまで)
	// {
	// buf1 = malloc (sizeof(char) * BUFFER_SIZE + 1);
	// if (!buf1)
	// 	return (0);
	
	// flag = read(fd,buf1, BUFFER_SIZE);
	// if (flag < 0)
	// 	return 0;




	// }
	
	
	// // {

	// // }
	// for (int i = 0;i<1;i++)
	
	// save = malloc(sizeof(char) * BUFFER_SIZE + 1);
	return (0);
}


int main(void)
{
    // 変数定義
    int fd1;
    // char buf[BUF_SIZE];

    fd1 = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   
    // ファイルのオープン
	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1)
	{
			printf("ファイルオープンエラー\n");
			return 0;
	}
	// byte_num = read(fd1, &buf[0], 5);
    // ファイルから5バイト読み込み
	char **line;
	get_next_line(fd1, line);

   
    // ファイルを閉じる
    close(fd1);
    return 0;
}

/ int get_next_line(int fd)
// {
// 	int flag;
// 	char memo[256];
// 	// int BUFFER_SIZE;
// 	int i;
// 	char *save;
// 	char *temp;
// 	char **line;
// 	// BUFFER_SIZE = 4;
// 	flag = 0;
// 	line = 0;
// 	// printf("~~~~~~~~~~~~~~~~~~~~~test1~~~~~~~~~~\n");
// 	// flag = read(fd,&memo[0], BUFFER_SIZE);
// 	if (flag == -1)
// 		return (0);
// 	// if (flag == 1) //ファイルの終端にたどり着いた時
// 	if (flag > 0)
// 	{
// 		// printf("~~~~~~~~~~~test2~~~~~~~~~~~~~~~~~~~~~~~\n");
// 		flag = read(fd,&memo[0], BUFFER_SIZE);
// 		// flag = read(fd,&memo[0], BUFFER_SIZE);
// 		// flag = read(fd,&memo[0], BUFFER_SIZE);
// 		i = 0;
// 		while(i < BUFFER_SIZE)
// 		{
// 			// printf("~~~~~~~~~~~~~~~~~~~~~~test3~~~~~~~\n");

// 			if (check(memo[i]) != 0)
// 			{
// 			// printf("---------------test4----------------------\n");

// 				memo[i] = 0;//関数を使うために改行をヌルにする
// 				temp = malloc(sizeof(char) * ((ft_strlen)(save) + i + 1 ));
// 				temp = ft_strjoin(save , &memo[0]); 
// 				*line = temp;
// 				save = &memo[i + 1];//saveに残りの文字列の先頭ポインタを入れる
// 				// printf("%s\n",temp);
// 				return (0);
// 			}
// 			i++;

// 		}

// 	}
// 	return (0);


// }