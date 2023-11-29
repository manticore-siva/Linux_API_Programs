/////////////////////////////////////////////////////////////////////////
//                                                                     //
//   Authore Name : Sivaprakasam.v                                     //
//   Title        : File permision Checker                             //
//   File Name    : File_permision_Checker.c                           //
//   Date         : 28/11/2023                                         //
//                                                                     // 
/////////////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
        // Declaration Necessary variables
        int r_stat;

        struct stat f_stat;
        struct timespec st_mtim;

        char *arr[3] = {"Others Permision : ","Group Permision  : ","Owner permision  : "};
        char *per[3] = {"Execuite ","Write ","Read "};

    for(int count = 1; count < argc; count ++)
    {
        //  get a permision value
        mode_t permision;

        // r variable used to shifting a permision data
        int r = 0;
        
        // Collect data from Source file
        r_stat = stat(argv[count], &f_stat); 

        // if faill stat()
        if(r_stat == -1)
        {
            perror("stat()");
            exit(-1);
        }

        // if Pass stat()
        else if (r_stat == 0)
        {
            // print size in Bytes
            printf("Size : %lu  Bytes \n",f_stat.st_size);

            // print size in Kb
            float f = (float)f_stat.st_size;
            printf("Size : %f Kbytes \n",f/1024);

            // Get a permision values
            permision = f_stat.st_mode;
            printf("permision octal : %o\n",permision);

            for(int j = 0; j < 3; j++)
            {
                // print permision name
                printf("%s",arr[j]);

                for(int i=0; i <3; i++)
                {
                    // check a read, write, execuite permision
                    if( (permision >> r) & (1 << i)) 
                        printf("%s",per[i]); 
                }
                        printf("\n");
                        // 3 time right shifting permision values
                        r += 3;
            }
        }
          // print lastmodification time
          printf("Last modification time : %s",ctime(&f_stat.st_mtim.tv_sec));
    }
}
