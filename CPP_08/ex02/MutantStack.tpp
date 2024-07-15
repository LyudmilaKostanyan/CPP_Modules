#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other)
{
	std::stack<T>::stack(other);
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

#endif