#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char *argv[])
{

   char buf[512],wr_buf[512];	
   int ret,ret1,status;
   int npfd1,fd1,fd2,fd3,pfd[2];
   struct stat s1,s2;

   ret = mkfifo(argv[1],0600);
   //ret is just the return value used for error checking 
   npfd1 = open(argv[1], O_RDONLY); //opening the named pipe for reading
   printf("this is after open \n"); 
                                    //only
   if(npfd1<0) {perror("error in opening the named pipe"); exit(1); }
	   
   while( (ret1 = read(npfd1,buf,512)) >0)
	   {
		   //printf("%s\n", buf);
                   write(STDOUT_FILENO,buf,ret1);
		   //fflush(stdout);
	   }  
	   if(ret1<0){ } 
	   close(npfd1);

   exit(0);

} 	 
	
