#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>




int get_next_line(int fd)
{
	int BUFFER_SIZE;
	int	flag;
	char *buf1;
	char *line;
	static char *save;
	int	i;
    char *memo;

	flag = 0;
	BUFFER_SIZE = 4;
	if (flag == -1)
		return (0);
	save = malloc(sizeof(char) * 1);
	save[0] = 0;
	read(fd, memo, BUFFER_SIZE);
    char *test1 = memo;
    printf("%c\n", test1[0]);
    
	

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

   
    // ファイルのオープン
	fd1 = open("test.txt", O_RDONLY);
	// if (fd1 == -1)
	// {
	// 		printf("ファイルオープンエラー\n");
	// 		return 0;
	// }
	// byte_num = read(fd1, &buf[0], 5);
    // ファイルから5バイト読み込み
	get_next_line(fd1);
    // ファイルを閉じる
    close(fd1);
    return 0;
}