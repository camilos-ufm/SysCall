#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#define bool int 
// structure of a stack node 
struct sNode { 
	char data; 
	struct sNode* next; 
}; 

// Function to push an item to stack 
void push(struct sNode** top_ref, int new_data); 

// Function to pop an item from stack 
int pop(struct sNode** top_ref); 

// Returns 1 if character1 and character2 are matching left 
// and right Brackets 
bool isMatchingPair(char character1, char character2) 
{ 
	if (character1 == '(' && character2 == ')') 
		return 1; 
	else if (character1 == '{' && character2 == '}') 
		return 1; 
	else if (character1 == '[' && character2 == ']') 
		return 1; 
	else
		return 0; 
} 

/* function to print string to kernel */
/* syscall number 333 */

SYSCALL_DEFINE2(printstring, char *, expr, int, n)
{
    printk("my_syscall_1 : %d\n", n);
	printk("my_syscall_1 : %c\n", expr[0]);
	int i = 0;
    for (i = 1; i < n; i++) {
        printk("my_syscall_1 : %c\n", expr[i]);
    }

	int i = 0; 

	// Declare an empty character stack 
	struct sNode* stack = NULL; 

	// Traverse the given expression to check matching 
	// brackets 
	while (i < n) 
	{ 
		// If the exp[i] is a starting bracket then push 
		// it 
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') 
			push(&stack, exp[i]); 

		// If exp[i] is an ending bracket then pop from 
		// stack and check if the popped bracket is a 
		// matching pair*/ 
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') { 

			// If we see an ending bracket without a pair 
			// then return false 
			if (stack == NULL) 
				return 0; 

			// Pop the top element from stack, if it is not 
			// a pair bracket of character then there is a 
			// mismatch. 
			// his happens for expressions like {(}) 
			else if (!isMatchingPair(pop(&stack), exp[i])) 
				return 0; 
		} 
		i++; 
	} 

	// If there is something left in expression then there 
	// is a starting bracket without a closing 
	// bracket 
    printk("my_func\n");
	if (stack == NULL) 
		return 1; // balanced 
	else
		return 0; // not balanced 


	// printk("my_syscall_1 : %d\n", n);
	// printk("my_syscall_1 : %c\n", expr[0]);
	// int i = 0;
	// for (i = 1; i < n; i++) {
	// 	printk("my_syscall_1 : %c\n", expr[i]);
	// }
	// return 0;

        //char buf[256];
        //unsigned long lenleft = len;
        //unsigned long chunklen = sizeof(buf);       
	//while( lenleft > 0 ){
        //        if( lenleft < chunklen ) 
	//		chunklen = lenleft;
        //        if( copy_from_user(buf, src, chunklen) )
	//	{
    	//		return -EFAULT;
    	//	}
        //        lenleft -= chunklen;
        //}
    
        //printk("%s\n", buf);
    
        //return 0;
}

// Function to push an item to stack 
void push(struct sNode** top_ref, int new_data) 
{ 
	// allocate node 
	struct sNode* new_node 
		= (struct sNode*) kmalloc(sizeof(struct sNode), GFP_KERNEL); 

	if (new_node == NULL) { 
		printk("Stack overflow n"); 
		// getchar(); 
		// exit(0); 
        return 0;
	} 

	// put in the data 
	new_node->data = new_data; 

	// link the old list off the new node 
	new_node->next = (*top_ref); 

	// move the head to point to the new node 
	(*top_ref) = new_node; 
} 

// Function to pop an item from stack 
int pop(struct sNode** top_ref) 
{ 
	char res; 
	struct sNode* top; 

	// If stack is empty then error 
	if (*top_ref == NULL) { 
		printk("Stack overflow n"); 
		// getchar(); 
		// exit(0); 
        return 0;
	} 
	else { 
		top = *top_ref; 
		res = top->data; 
		*top_ref = top->next; 
		kfree(top); 
		return res; 
	} 
}
