#include <linux/kernel.h>
#define bool int

// function to check if parenthesis are
// balanced.
asmlinkage bool areBracketsBalanced(char *expr, int *n)
{
	// Base cases
	if (n[0] == 0)
		return 1;
	if (n[0] == 1)
		return 0;
	if (expr[0] == ')' || expr[0] == '}' || expr[0] == ']')
		return 0;

	// Search for closing bracket for first
	// opening bracket.
    char c = (expr[0]);
    char closing;
    if (c == '(')
		closing = ')';
	if (c == '{')
		closing = '}';
	if (c == '[')
		closing = ']';

	// count is used to handle cases like
	// "((()))". We basically need to
	// consider matching closing bracket.
	int i, count = 0;
	for (i = 1; i < n[0]; i++) {
        printk("my_syscall_1 : %d\n", i);
		if (expr[i] == expr[0])
			count++;
		if (expr[i] == closing) {
			if (count == 0)
				break;
			count--;
		}
	}
    printk("My func rip\n");
	// If we did not find a closing
	// bracket
	if (i == n[0])
		return 0;

	// If closing bracket was next
	// to open
	if (i == 1)
		return areBracketsBalanced(expr[2], n[2]);

	// If closing bracket was somewhere
	// in middle.
    // n[0] = i - 1;
	// return areBracketsBalanced(expr[1], n[0]) && areBracketsBalanced(expr + i + 1, n - i - 1);
}