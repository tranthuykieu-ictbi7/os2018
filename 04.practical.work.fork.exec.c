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
        printf("I'm child after forl(), launching tree -h\n");
        char *args[] = {"tree", "-h", NULL};
        execvp("tree", args);
        printf("Finished launching tree -h \n");
    }
    else 
    printf("After fork(), the parent is: %d, the child is: %d", pid0, pid1);
    return 0;   
        
}
      
