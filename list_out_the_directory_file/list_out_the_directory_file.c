/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Listout_the_directory_and files                    //
//   File Name    : list_out_the_directory_file.c                      //
//   Date         : 24/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdio.h>

int main()
{
    int ret;

    ret = execl("/usr/bin/tree", "tree","-l",  NULL);

    if(ret == -1)
    {
        perror("");
    }
    else 
    {
        perror("");
    }
}
