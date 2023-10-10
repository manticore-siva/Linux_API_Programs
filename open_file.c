
/* //////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : Create a New File and Close the file use LINUX API            //
//   Date  : 10/10/2023                                                    //
//                                                                         // 
/////////////////////////////////////////////////////////////////////////// */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int OpenFlag,fd;         // fd File descriptor
    OpenFlag = O_CREAT;      // Openflag value If pathname does not exist, create it as a regular file
    mode_t Fileprem;         // File permision mode type 
    Fileprem = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH; // Given a file premission to USER, GROUP and OTHERS
    fd = open("Demofile.txt",OpenFlag,Fileprem);    // Create a new file and get return values
    if(fd == -1)
    {
        printf("Error Occurred while Creating file\n");  // If not create file 
    }
    else
    {
        printf("File Created Successfully\n");           // Successfully file created
    }
    fd = close(fd);
    if(fd == -1)
    {
        printf("Error Occurred while Close file\n");      // If file not closed
    }
    else
    {
        printf("File Close Successfully\n");              // File close Successfully
    }
}
