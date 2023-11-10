/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Make a Directory                                   //
//   File Name    : bat.c                                              //
//   Date         : 08/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

#define PERMISION S_IRWXU|S_IRWXG|S_IROTH

int main(int arguc, char *arguv[])
{
    int r_mkdir;
     mode_t mode, mkdir_ret;

     mode = PERMISION;

    // int mkdir(const char *pathname, mode_t mode);
    r_mkdir = mkdir(arguv[1], mode);

    if(r_mkdir == 0) 
    {
        perror("mkdir() : ");
    }
    else if (r_mkdir == -1)
    {
        perror("mkdir() : ");
    }
}
