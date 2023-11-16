/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Merge two file                                     //
//   File Name    : merge_two_file.c                                   //
//   Date         : 15/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 2048

// arguv[1] source file arguv[2] destination file
int main(int argc, char *arguv[])
{
    // Declare Necessary Variable
    int open_fd1, fd2, flag=0;
    ssize_t read_bytes, w_ret;
    off_t offset = SEEK_END, ret_lseek;

    // useing as temprorary storage
    char *buf[BUF_SIZE];

    // open a first file
    open_fd1 = open(arguv[1], flag);

    // if faill while open a file
    if(open_fd1 == -1)
    {
        perror("open() file1");
        exit(-1);
    }

    // if pass while open a file
    else if(open_fd1 > 0)
    {
        perror("open() file1");

        // read a destination file as a bytes 
        read_bytes = read(open_fd1, buf, BUF_SIZE);
        
        // if faill while read a file
        if(read_bytes == -1)
        {
            perror("read() file1");
            close(open_fd1);
            exit(-2);
        }
        // if pass while read a file
        else if(read_bytes > 0)
        {
            perror("read() file1");
            close(open_fd1);
            perror("close() file1");
        }    
    }

    // open second file
    fd2 = open(arguv[2], O_RDWR);

    // if faill open a second file
    if( fd2 == -1)
    {
        perror("open() file2");
    }

    // if pass open a second file
    else if (fd2 > 0)
    {
        perror("open() file2");

        // set curser at last to destination file
        ret_lseek = lseek(fd2, 10000, SEEK_END);

        // if faill while set lseek a second file
        if(ret_lseek == -1)
        {
            perror("lseek() file2");
            close(fd2);
            perror("close() file2");
        }

        // if pass while set lseek a second file
        else if (ret_lseek > 0)
        {
            perror("lseek() file2");

            // Write bytes to destination file
            w_ret = write(fd2, buf, read_bytes);

           // if faill while write a second file
           if (w_ret == -1)
           {
               printf("fd2 : %d\n",fd2);
               perror("write() file2");
               close(fd2);
               perror("close() file2");
           }
           // if pass while write a second file
           else if (w_ret > 0)
           {
               perror("write()file2");
               close(fd2);
               perror("close() file2");
           } 
        }
    }
}
