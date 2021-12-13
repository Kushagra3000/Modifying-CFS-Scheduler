#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/time.h>


int main()
{  

	pid_t pid = fork();
	if(pid != 0){
		int flag2=0;
		long soft_t;
		soft_t = -11;
		
		if(soft_t<0 || soft_t>=100000000000){
			flag2=1;
		}
		int flag= syscall(335,getpid(),soft_t);
		if(flag == 0 && flag2==0){
		
			struct timespec s_time, f_time; 
			clock_gettime(CLOCK_REALTIME, &s_time); 
	
			long sum=0;
			for (int i=0; i<1000000000;i++){
				sum++;
			}  
			clock_gettime(CLOCK_REALTIME, &f_time); 
			long execution_time = f_time.tv_nsec - s_time.tv_nsec; 
			if (s_time.tv_nsec > f_time.tv_nsec) 
	 			execution_time += 1000000000;
 	
			//printf("Process with soft_time, time taken in ns:  %ld\n",execution_time);
			printf("In Parent process, time taken in ns:  %ld\n",execution_time);
		}

		else {
			if(flag!=0)
			{
				printf("System call didn't execute!!\n");
				perror("Error ");
				printf("Error No.: %d\n", errno);
			}
			else{
				printf("System call didn't execute!!\n");
				printf("Error: Invalid argument");
				printf("Error No.: 22");
			}
		}
		wait(NULL);
	
	}


	else{
		wait(NULL);
		
		
		struct timespec s_time, f_time; 
		clock_gettime(CLOCK_REALTIME, &s_time); 

		long sum=0;
		for (int i=0; i<1000000000;i++){
			sum++;
		}  
		clock_gettime(CLOCK_REALTIME, &f_time); 
		long execution_time = f_time.tv_nsec - s_time.tv_nsec; 
		if (s_time.tv_nsec > f_time.tv_nsec) 
 			execution_time += 1000000000;
		
		//printf("Process without soft_time, time taken in ns:  %ld\n",execution_time);
		printf("In child process, time taken in ns:  %ld\n",execution_time);
	}

	return 0;

}
