/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : change ownership of a file                         //
//   File Name    : chown.c                                            //
//   Date         : 22/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret_chown;
    uid_t u_id;
    gid_t g_id;

    // get a uid value
    u_id = atoi(argv[2]);

    // get a gid value
    g_id = atoi(argv[3]);

    // change a ownership of the destination file
    ret_chown = chown(argv[1], u_id, g_id);

    // faill to change ownership
   if(ret_chown == -1)
   {
       perror("chown()");
       exit(-1);
   } 

    // pass to change ownership
   else if(ret_chown == 0)
   {
       perror("chown()");
   }
}
