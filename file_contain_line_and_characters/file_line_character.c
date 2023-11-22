/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : File have how many line and characters             //
//   File Name    : file_contain_line_and_charcters.c                  //
//   Date         : 08/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 102400

int fun_read(int);

int main(int argc, char *argv[])
{
        int fd, flag=0;
        
        fd = open(argv[1], flag);

        // if faill to open
        if(fd == -1)
        {
            // print the error message
            perror("open():");
            exit(-1);
        }

       // if pass to open
        else if(fd > 0)
        {
            // ready to read destination file
            fun_read(fd);

            // close the file
            close(fd);
        }
}

int fun_read(int fd)
{
    int l_no = 0;
    ssize_t read_bytes;
    char buf[BUF_SIZE];

    read_bytes = read(fd, buf, BUF_SIZE);

    // if faill to read
    if(read_bytes == -1)
    {
        perror("read()");
        exit(-2);
    }

    else if(read_bytes >= 0)
    {
        for(int count=0; count < read_bytes; count++)
        {
            if(buf[count] == '\n')
                l_no++;
        }
    }
    printf("Number of characters : %ld\n", read_bytes);
    printf("Number of Line       : %d\n", l_no);
}
