#include <linux/kernel.h>
#define bool int

char findClosing(char c)
{
	if (c == '(')
		return ')';
	if (c == '{')
		return '}';
	if (c == '[')
		return ']';
	return -1;
}

// function to check if parenthesis are
// balanced.
asmlinkage bool areBracketsBalanced(char *expr, int n)
{
    // printk("my_syscall_1 : %d\n", n);
	// printk("my_syscall_1 : %c\n", expr[0]);
	// int i = 0;
    // for (i = 1; i < n; i++) {
    //     printk("my_syscall_1 : %c\n", expr[i]);
    // }
    // return 0;
    // printk("my_syscall_1 : %d\n", n);
	// Base cases
	if (n == 0)
		return 1;
	if (n == 1)
		return 0;
	if (expr[1] == ')' || expr[1] == '}' || expr[1] == ']')
		return 0;

	// Search for closing bracket for first
	// opening bracket.
	char closing = findClosing(expr[0]);

	// count is used to handle cases like
	// "((()))". We basically need to
	// consider matching closing bracket.
	int i, count = 0;
	for (i = 1; i < n; i++) {
        printk("my_syscall_1 : %c\n", expr[i]);
		if (expr[i] == expr[0])
			count++;
		if (expr[i] == closing) {
			if (count == 0)
				break;
			count--;
		}
	}
    printk("My func rip\n");
	If we did not find a closing
	bracket
	if (i == n)
		return 0;

	If closing bracket was next
	to open
	if (i == 1)
		return areBracketsBalanced(expr + 2, n - 2);

	If closing bracket was somewhere
	in middle.
	return areBracketsBalanced(expr + 1, i - 1) && areBracketsBalanced(expr + i + 1, n - i - 1);
}