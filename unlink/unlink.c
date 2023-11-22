/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : Unlink Sytem call                                  //
//   File Name    : unlink.c                                           //
//   Date         : 21/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret_unlink;

    ret_unlink = unlink(argv[1]);

    if(ret_unlink == -1)
    {
        perror("unlink()");
        exit(-1);
    }

    else if(ret_unlink == 0)
    {
        perror("unlink()");
    }
}
