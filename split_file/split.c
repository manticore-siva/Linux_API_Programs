/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Split a file                                       //
//   File Name    : split.c                                            //
//   Date         : 22/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 102400

int fun_read (int);
int fun_write(char * , int, int);

int main(int argc, char *argv[])
{
    int fd;
    
    // open a file
    fd = open(argv[1], 0);

    if(fd == -1)
    {
        perror("open()");
        exit(-1);
    }

    // if pass to open a file
    else if(fd > 0)
    {
        perror("open()");
        fun_read(fd);
    }

    return 0;
}

int fun_read(int fd)
{
    ssize_t read_bytes;
    char buf[BUF_SIZE];
    int l_no = 0, c_new_line = 0, r_count=0, count;
    
    // read a source file
    read_bytes = read(fd, buf, BUF_SIZE);

    // if faill to read
    if(read_bytes == -1)
    {
        perror("read()");
        close(fd);
        exit(-2);
    }

    // if pass to read
    else if(read_bytes > 0)
    {
        printf("Totall read bytes : %ld\n",read_bytes);

        perror("read()");
        for(count=0; count < read_bytes ; count++)
        {
            if(buf[count] == '\n')
                l_no++;
        }

        // set null at last byte
        buf[count] = '\0';

        // print number of line 
        printf("No of line : %d\n",l_no);

        // split half line of datas
        l_no /= 2;
        
        // print spilit data byte counts
        printf("half No of line : %d\n",l_no);
    }
        
        // read a byte untill half line
        for(count=0; count < read_bytes ; count++)
        {
            r_count++;

               if(buf[count] == '\n')
               {
                   c_new_line++;
               }
               if(c_new_line == l_no)
                   break;
        }

        // print half byte of data count
        printf("half read bytes : %d\n",r_count);

        // move to write function
        fun_write(buf, r_count, fd);
}

int fun_write(char *buf, int position, int fd)
{
        ssize_t w_ret;
        int r_fd;

        // open a new file
        r_fd = open("1split.txt", O_CREAT | O_RDWR , S_IRWXU | S_IRWXO ) ;

        // if faill to open first spilit file
        if(r_fd == -1)
        {
            perror("open2()");
            exit(-3);
        }

        // if pass to open first spilit file
        else if(r_fd > 0)
        {
            w_ret = write(r_fd, buf, position);
            close(r_fd);
        }

       r_fd = open("2split.txt", O_CREAT | O_RDWR , S_IRWXU | S_IRWXO );

        // if pass to open second spilit file
       if(r_fd == -1)
       {
            perror("open2()");
            exit(-3);
       }

        // if pass to open second spilit file
       else if(r_fd > 0)
       {
            w_ret = write(r_fd, buf+(position+1), 942);
            close(r_fd);
       }
}
