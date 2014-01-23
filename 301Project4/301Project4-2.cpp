#include <iostream>
#include <cstring>
#include <cstdlib>
#include "stack.h"
using namespace std;
int main()
{
	stack<int, 80> stack;
	stack.ClearStack();
	char * token;
	char line[80];
	int x;
	int y;
	cout << "Enter a postfix expression: ";
	cin.getline(line, 79);
	token = strtok(line, ", ");
	while(token!=NULL)
	{
			switch(*token)
			{
				case '+': x=stack.pop(); y=stack.pop(); stack.push(y+x); break;
				case '-': x=stack.pop(); y=stack.pop(); stack.push(y-x); break;
				case '*': x=stack.pop(); y=stack.pop(); stack.push(y*x); break;
				case '/': x=stack.pop(); y=stack.pop(); stack.push(y/x); break;
				case '$': cout << "It's value is " << stack.pop(); break;
				default: stack.push(atoi(token));
			}
		token=strtok(NULL, ", ");
	}
	return 0;
}
/*OUTPUT
Enter a postfix expression: 20 10 + 50 40 - 5 4 * 9 3 / + $
It's value is 23
 */
