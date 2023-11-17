/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Create Multilple Directorys                        //
//   File Name    : create_multiple_directory.c                        //
//   Date         : 16/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret_mkdir, ret_rmdir;
    mode_t mode;

    // Declare permision 
    // read, write and execuite permision to owner, group and others
    mode = 0777;

    // now create a directorys
    for(int count = 1; count < argc; count++)
    {
        // make directory systemcall
        ret_mkdir = mkdir(argv[count], mode);

        // if faill
        if(ret_mkdir == -1)
        {
            perror("mkdir()");
            printf("%s\n",argv[count]);
            exit(-1);
        }
        // if pass
        else 
        {
            perror("mkdir()");
            printf("%s\n",argv[count]);
        }
        // wait one secand
        sleep(1);
    }

    // deleting directory

    for(int count = 1; count < argc; count++)
    {
        // delete directory systemcall
        ret_rmdir = rmdir(argv[count]);

        // if faill
        if(ret_mkdir == -1)
        {
            perror("rmdir()");
            printf("%s\n",argv[count]);
            exit(-1);
        }
        // if pass
        else 
        {
            perror("rmdir()");
            printf("%s\n",argv[count]);
        }
        // wait one secand
        sleep(1);
    }
}
