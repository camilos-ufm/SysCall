#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
    char exp[10] = "((5-3))[2]"; 

    // Function call 
    if (syscall(548,&exp[0])) 
        printf("Balanced \n"); 
    else
        printf("Not Balanced \n"); 
    long int xd = syscall(548);
    printf("System call sys_hello returned %ld\n", xd);
    
    return 0;
}

// int main() 
// { 
// 	char exp[10] = "{5-3)}[2]"; 

// 	// Function call 
// 	if (areBracketsBalanced(&exp[0])) 
// 		printf("Balanced \n"); 
// 	else
// 		printf("Not Balanced \n"); 
// 	return 0; 
// } 