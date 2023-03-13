/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:34:27 by hde-camp          #+#    #+#             */
/*   Updated: 2023/03/09 15:39:25 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	//Canonical form declaration START
	MutantStack(){};
	MutantStack(MutantStack const& origin){
		*this = origin;
	};
	MutantStack& operator=(MutantStack const& origin){
		this->c = origin.c;
	};
	~MutantStack(){};
	//Canonical form declaration END
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	iterator begin(){return (this->c.begin());};
	iterator end(){return (this->c.end());};
	reverse_iterator rbegin(){return (this->c.rbegin());};
	reverse_iterator rend(){return (this->c.rend());};
};