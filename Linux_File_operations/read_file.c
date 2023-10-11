/* //////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : Read a File and Close the file use LINUX API                  //
//   Date  : 11/10/2023                                                    //
//                                                                         // 
/////////////////////////////////////////////////////////////////////////// */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 512

int main(int argc, char *argv[])
{
    int openFlag, c_count, fd;   
    ssize_t numRead;
    char buf[BUF_SIZE];

    openFlag = O_CREAT;  // If pathname does not exist, create it as a regular file.
    
    // int open(const char *pathname, int flags);
    fd = open(argv[1],openFlag);

    if(fd == -1)
    {
        printf("%s: Error opening a file %s\n",argv[0],argv[1]);   // if not openaing a file print command with fime name
        exit(10);  // exit 
    }
    else
    {
        numRead = read(fd, buf, BUF_SIZE);
    }
    for(c_count = 0; c_count<numRead; c_count++)
        printf("%c",buf[c_count]);               // print characters 

    close(fd);                             // Close the file
    exit(0);
}
