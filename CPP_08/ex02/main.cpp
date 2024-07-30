#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "list:" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_front(5);
		mstack.push_front(17);

		std::cout << "top: " << mstack.front() << std::endl;

		mstack.pop_front();

		std::cout << "size: " << mstack.size() << std::endl;

		mstack.push_front(3);
		mstack.push_front(5);
		mstack.push_front(737);
		//[...]
		mstack.push_front(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}