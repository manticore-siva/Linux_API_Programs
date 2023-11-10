/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : System calls used to Print a details about Battery //
//   File Name    : bat.c                                              //
//   Date         : 06/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1024
#define FILE_PATH_NAME "/sys/class/power_supply/BAT1/uevent"

int main()
{
    // declare file descriptor and flag, here flag value 0 no need to create new file
    int open_fd,flag=0;
    ssize_t read_fd,write_fd;
    char *buf[BUF_SIZE];

    // here given battery details file path and flag
   // open_fd = open ("/sys/class/power_supply/BAT1/uevent",flag);
    open_fd = open (FILE_PATH_NAME,flag);

    // if error when try to open a file
    if(open_fd == -1)
    {
        perror("Error opening first file");
        exit(-1);
    }
    else if(open_fd > 0)     // if sucessfully to open a file
    {
        perror("Sucessfully to Open a file");
        read_fd = read(open_fd, buf, BUF_SIZE); // read a data from given path battery file 

        if(read_fd == -1) // if not to read
        {
            perror("Error While read a file");
            close(open_fd);
            exit(-2);
        }
        else if(read_fd > 0) // if pass to read a datas
        {
           write_fd =  write(STDOUT_FILENO,buf,BUF_SIZE); // write a from buffer
           if(write_fd == -1) // if faill to write
           {
               perror("Error while Write a file");
               close(open_fd);
               close(read_fd);
               exit(-3);
           }
           else if(write_fd > 0) //  if pass to write
           {
               perror("Sucess fully to write");
           }
        }
    }
    // finally pass above steps properly close the used file descriptors 
    close(open_fd);
    close(read_fd);
    close(write_fd);
    return 0;
}
