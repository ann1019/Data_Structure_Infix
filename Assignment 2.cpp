#include <iostream>
#include <string>
using namespace std;
#include "Stack.cpp"

enum precedence{ lparen, rparen, add, reduce, times, divide, mod, eos, operand };

int evaluateInfix(string &expr);
precedence getToken(string &expr, char &symbol, string::iterator &it);
void performOperation(precedence op, Stack< int > &operandStack);

int main()
{
	string expr;
	cout << "Enter an infix expression: ";
	cin >> expr;

	cout << endl << expr << " = " << evaluateInfix(expr) << endl << endl;

	system("pause");
}

int evaluateInfix(string &expr)
{
	int beforePrior[9] = { 5, 1, 3, 3, 4, 4, 4, 0, 0 };
	int afterPrior[9]  = { 2, 1, 3, 3, 4, 4, 4, 0, 0 };
	expr += '\0';//�W�[�@�ӪŦr���A���M���N����(it�������~)
	string::iterator it = expr.begin();
	char symbol;//��operand���r���x�s
	precedence token;//�ݬO���Ӻ���
	Stack<int> operands;
	Stack<int> operators;
	//Stack<precedence> operators;
	operators.push(eos);
	token=getToken(expr, symbol, it);
	int isparen = 0;
	while (token != eos && it<(expr.end()-1))
	{
		/*cout << "operands: ";
		for (int i = 0; i < operands.size(); i++)
			cout << operands.stack.operator[](i) << " ";
		cout << endl << "operators: ";
		for (int i = 0; i < operators.size(); i++)
			cout << operators.stack.operator[](i) << " ";
		cout << endl<<endl;
		//cout << "i am here" << endl;*/
		if (token == operand)
			operands.push(symbol - '0');
		else 
		{
			//if (beforePrior[token] > afterPrior[operators.top()])
			isparen = 0;
			while (beforePrior[token] <= afterPrior[operators.top()] && !operators.empty())
			{
				cout << "i am here" << endl;
				performOperation((precedence)operators.top(), operands);
				//operands.push(token);
				operators.pop();
				if (token == rparen && operators.top() == lparen)
				{
					isparen = 1;//��ܧR��(���n�A�W�[ 
					operators.pop();
					break;
				}
				
			}
			if (isparen==0)//�S�����A���A�n�⨺��operator�W�[
				operators.push(token);
		}
		/*
		cout << "operands: ";
		for (int i = 0; i < operands.size(); i++)
			cout << operands.stack.operator[](i) <<" ";
		cout << endl<<"operators: ";
		for (int i = 0; i < operators.size(); i++)
			cout << operators.stack.operator[](i) << " ";
		cout << endl;
		*/
		it++;
		token = getToken(expr, symbol, it);
	}
	while(!operators.empty())
	{
		performOperation((precedence)operators.top(), operands);
		operators.pop();
	}
		
	cout << "operands: ";
	for (int i = 0; i < operands.size(); i++)
		cout << operands.stack.operator[](i) << " ";
	cout << endl << "operators: ";
	for (int i = 0; i < operators.size(); i++)
		cout << operators.stack.operator[](i) << " ";
	cout << endl;
	expr.pop_back();
	int result = operands.top();
	return result;
}

precedence getToken(string &expr, char &symbol, string::iterator &it)
{
	symbol = *it;
	switch (symbol)
	{
		/*
	case '(': cout << "("<<endl; return lparen;
	case ')': cout << ")" << endl; return rparen;
	case '+': cout << "+" << endl; return add;
	case '-': cout << "-" << endl; return reduce;
	case '/': cout << "/" << endl; return divide;
	case '*': cout << "*" << endl; return times;
	case '%': cout << "%" << endl; return mod;
	case '\0':cout << "\0" << endl; return eos;
	default: cout << symbol << endl; return operand;*/
	case '(':  return lparen;
	case ')':  return rparen;
	case '+':  return add;
	case '-':  return reduce;
	case '/':  return divide;
	case '*':  return times;
	case '%':  return mod;
	case '\0': return eos;
	default:  return operand;
	}
	
}

void performOperation(precedence op, Stack< int > &operandStack)
{
	if (op == lparen || op == rparen || op == eos)
		return;
	int num2 = operandStack.top();
	operandStack.pop();
	int num1 = operandStack.top();
	operandStack.pop();
	switch (op)
	{
	case add: operandStack.push(num1 + num2); break;
	case reduce:operandStack.push(num1 - num2); break;
	case times:operandStack.push(num1 * num2); break;
	case divide:operandStack.push(num1 / num2); break;
	case mod:operandStack.push(num1 % num2); break;
	default:return;
	}
}