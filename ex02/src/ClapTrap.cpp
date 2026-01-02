/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:42:51 by JuHyeon           #+#    #+#             */
/*   Updated: 2026/01/02 06:30:53 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " can't do anything";
		if (this->_energyPoints <= 0)
			std::cout << " with no energyPoints" << std::endl;
		else if (this->_hitPoints <= 0)
			std::cout << " with no hitPoints" << std::endl;
		else
			std::cout << " with something reason" << std::endl;
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_hitPoints < amount)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount 
					<< " damage! (Current HP: " << this->_hitPoints << ")" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself, getting " << amount 
					<< " hit points! (Current HP: " << this->_hitPoints << ")" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't do anything" << std::endl;
}
