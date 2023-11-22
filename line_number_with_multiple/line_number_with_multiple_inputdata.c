/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : line_number_with_multiple_given_input_line_no      //
//   File Name    : line_number_with_multiple_given_input_line_no .c   //
//   Date         : 19/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 102400

char buf[BUF_SIZE];

int  open_fun(char *, int );
int  read_fun(int fd);
off_t lseek_fun(int, off_t, int);

int main(int argc, char *argv[])
{
    int fd, ret, l_no = 0, loop_count=0, read_line, count, size=0, temp;
    int arr[10];

    read_line = atoi(argv[2]);
    temp = read_line;

    // open a file
    fd = open_fun(argv[1], 0);

    // read file
    ret = read_fun(fd);

    for(count = 0; count < ret; count++)
    {
        if(buf[count] == '\n')
        {
            l_no++;
            arr[size] = (count+1);
            size++;
        }
    }
    
    arr[--size] = '\0';

    loop_count = l_no / read_line;

    int d1 = temp-1, d=0;
    printf("temp : %d\n",temp-1);

    for(int j=0; j < loop_count; j++)
    {
        d = d1*temp;
        d = arr[d1*temp];

        for(int cd = d; buf[cd] != '\n'; cd++) 
                printf("%c", buf[cd]);

        d1 += temp; 
    }
}

int open_fun(char *buf, int flag)
{
    int fd;
    fd = open(buf, flag);

    if(fd == -1)
    {
        perror("open()");
        close(fd);
        exit(-1);
    }
    else if(fd > 0)
    
    {
        perror("open()");
        return fd;
    }
}

int read_fun(int fd)
{
    ssize_t ret;

    // read a Destination file
    ret = read(fd, buf, BUF_SIZE);

    if(ret == -1)
    {
        perror("read()");
        close(fd);
        exit(-2);
    }
    else if(ret > 0)
    {
        perror("read()");
        return (ret);
    }
}
