/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 23:56:25 by JuHyeon           #+#    #+#             */
/*   Updated: 2026/01/02 01:53:36 by JuHyeon          ###   ########.fr       */
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