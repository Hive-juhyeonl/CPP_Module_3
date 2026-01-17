/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 23:56:25 by JuHyeon           #+#    #+#             */
/*   Updated: 2026/01/17 13:38:19 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
parent member status	|	public	|	protected	|	private		|
		public			|	can use	|	can't use	|	can't use	|
		protected		|	can use	|	can use		|	can't use	|
		private			|				can't touch					|
*/
class ScavTrap : public ClapTrap
{
	private:
		bool	_keeperMode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		
		void	attack(const std::string& target);
		void	guardGate();
};

#endif