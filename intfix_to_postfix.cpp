#include<iostream>
#include<string>
#include<stack>

#define N char(12)

int pd(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}


void intfix_to_postfix(std::string &x)
{
	std::stack<char> st;
	std::string ans;
	st.push(N);
	for (char x : x)
	{
		if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
			ans.push_back(x);
		else if (x == '(')
		{
			st.push('(');
		}

		else if (x == ')')
		{
			while (st.top() != N && st.top() != '(')
			{
				ans.push_back(st.top());
				st.pop();
			}
			if (st.top() == '(')
				st.pop();
		}
		else 
		{
			while(pd(x) <= pd(st.top())&& st.top()!=N)
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.push(x);
		}
	}
	while (st.top() != N)
	{
		ans.push_back(st.top());
		st.pop();
	}
	std::cout << "POST FIX expression is : " << ans;
	
}

int main()
{
	std::string exp = "a+b*(c^d-e)^(f+g*h)-i";
	std::cout << "Enter an intfix strng : ";
	std::getline(std::cin,exp);
	std::cout << exp;
	intfix_to_postfix(exp);
	std::cin.get();
	return 0;
}
