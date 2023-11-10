/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Displaybrightness                                  //
//   File Name    : brightness.c                                       //
//   Date         : 08/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void Read(int *ptr);

#define PATH_FNAME "/sys/class/backlight/amdgpu_bl0/actual_brightness"

int main()
{
    int open_fd,flags;
    flags = 0;

    // use open system call to open backlight file
    open_fd = open(PATH_FNAME, flags);

    // if error while open a file
    if(open_fd == -1)
    {
        perror("open():");
        exit(-1);
    }
    // if success to open
    else if(open_fd > 0)
    {
        perror("open():");
        Read(&open_fd);
    }
    // close the file by use destination file descriptor
    close(open_fd);
    return 0;
}

void Read(int *ptr)
{
    int read_fd;
    char *buf[BUF_SIZE];
    char *msg = "Battery Percentage : ";

    // read a file by use destination file descriptor
    read_fd = read(*ptr, buf, BUF_SIZE);

    // if fail while read a file
    if(read_fd == -1)
    {
        perror("open():");
        close(*ptr);
        exit(-2);
    }
    // if success to read file
    else if(*ptr > 0)
    {
        write(STDOUT_FILENO, msg, 22);
        write(STDOUT_FILENO, buf, BUF_SIZE);
    }

    // close the file by use destination file descriptor
    close(read_fd);
}
