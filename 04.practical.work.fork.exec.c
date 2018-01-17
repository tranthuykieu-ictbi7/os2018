#include <stdio.h>
#include <unistd.h>

int main(){
    printf("I'm Kieu. This is my practical work 4:\n");
    int pid0 = fork();
    int pid1 = fork();

    if (pid0 == 0){
        printf("I am child after fork(), launching ps -ef\n");
        char *args[] = {"/bin/ps", "-ef", NULL};
        execvp("/bin/ps", args);
        printf("Finished launching ps -ef \n");
   }

    if (pid1 == 0){
        printf("I'm child after forl(), launching free -h\n");
        char *args[] = {"free", "-h", NULL};
        execvp("free", args);
        printf("Finished launching free -h \n");
    }
    else 
    printf("After fork(), child contains ps: %d, child contains free: %d", pid0, pid1);
    return 0;   
        
}
      
