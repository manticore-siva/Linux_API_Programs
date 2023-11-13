/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Read mouse file                                    //
//   File Name    : mouse.c                                            //
//   Date         : 08/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define PATHNAME "/dev/input/mouse2"
#define BUF_SIZE 1024

int main()
{
    int open_fd;
    ssize_t ret_read, ret_write;
    // add a input event structure
    struct input_event event;
    char *buf[BUF_SIZE];
    long int flag;

    // open a mouse file
    open_fd = open(PATHNAME, flag);

    // if error while open a file
    if(open_fd == -1)
    {
        perror("open() :");
        exit(-1);
    }


    //  if success to open a file
    else if (open_fd > 0)
    {
         while(1)
         {
            // read a mouse file 
            ret_read = read(open_fd, &event, sizeof(event));

            // if error while read a file
            if(ret_read == -1)
            {
                perror("read():");
                close(open_fd);
                exit(-2);
            }
            // if success to read
            else if(ret_read > 0)
                {
                    printf("time : %ld\n",event.time.tv_sec);
                    flag = event.time.tv_sec;
                    printf("flag : %ld\n",flag);
                    // Right click
                    if (flag == 10)
                        {
                            printf("Right Click\n");
                        }
                    // Left click
                     else if (flag == 9)
                        {
                             printf("Left Click\n");
                        }
                   // if error while write a file
                   if(ret_write == -1)
                    {
                      perror("write():");
                      exit(-3);
                    }
               }
         }
   }
    close(open_fd);
}
