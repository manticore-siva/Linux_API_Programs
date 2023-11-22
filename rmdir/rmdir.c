/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Delete a Directory                                 //
//   File Name    : rmdir.c                                            //
//   Date         : 08/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret_rmdir;

    // delete the destination directory
    ret_rmdir = rmdir(argv[1]);

    //if faill while deleting a directory
    if(ret_rmdir == -1)
    {
        perror("rmdir()");
        exit(-1);
    }

    // pass to delete directory
    else if(ret_rmdir == 0)
    {
        printf("Directory name : ");
        printf("%s\n",argv[1]);
        perror("rmdir()");
    }

    return 0;
}
