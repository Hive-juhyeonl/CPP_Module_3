/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:11:13 by JuHyeon           #+#    #+#             */
/*   Updated: 2026/01/17 14:43:58 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <cstdlib>

void	clear_screen()
{
	system("clear");
}

void	wait_for_enter()
{
	std::cout << "\n> Press ENTER to return to the menu...";
	std::cin.ignore(32767, '\n'); 
	std::cin.get(); 
}

// 1. Basic Actions Test
void test_basics(void)
{
	clear_screen();
	std::cout << "=== TEST 1: Basic Interactions ===\n" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	a.attack("Beta");
	b.takeDamage(0);
	b.beRepaired(5);

	wait_for_enter();
}

// 2. Energy Depletion Test
void test_energy(void)
{
	clear_screen();
	std::cout << "=== TEST 2: Energy Depletion ===\n" << std::endl;
	ClapTrap c("Charlie");
	for (int i = 1; i <= 11; i++)
	{
		if (i < 10)
			std::cout << "Attack #" << i << " : ";
		else
			std::cout << "Attack #" << i << ": ";
		c.attack("Target");
	}
	wait_for_enter();
}

// 3. Death Test
void test_death(void)
{
	clear_screen();
	std::cout << "=== TEST 3: Death Handling (0 HP) ===\n" << std::endl;
	ClapTrap d("Delta");
	d.takeDamage(9);
	d.takeDamage(2);
	d.takeDamage(1);
	d.attack("Enemy");
	d.beRepaired(10);
	wait_for_enter();
}

// 4. ScavTrap Test
void	test_scavtrap()
{
	{
		clear_screen();
		std::cout << "=== TEST 4: ScavTrap Special Features ===\n" << std::endl;
		ScavTrap s("Serena"); 
		s.attack("Target");
		s.guardGate();
		s.guardGate();
	}
	wait_for_enter();
}

// 5. FragTrap Test
void	test_fragtrap()
{
	{
		clear_screen();
		std::cout << "=== TEST 5: FragTrap (High Five) ===\n" << std::endl;
        FragTrap f("Fox");
        f.attack("Enemy");	// seg fault
        f.highFivesGuys();
	}
	wait_for_enter();
}

// 6. DiamondTrap Test
void	test_diamondtrap()
{
	{
		clear_screen();
		std::cout << "=== TEST 6: DiamondTrap (whoAmI) ===\n" << std::endl;
		DiamondTrap g("Golf");	// seg fault
		g.whoAmI();
		g.attack("Target");
		g.guardGate();
		g.highFivesGuys();
	}
	wait_for_enter();
}

int	main()
{
	int input;

	while (1)
	{
		clear_screen();
		std::cout << "==========================================" << std::endl;
		std::cout << "              CLAPTRAP TEST               " << std::endl;
		std::cout << "==========================================" << std::endl;
		std::cout << "1. Basic Actions (Attack, TakeDamage, BeRepaired)" << std::endl;
		std::cout << "2. Energy Check (What happens at 0 Energy?)" << std::endl;
		std::cout << "3. Death Check (What happens at 0 HP?)" << std::endl;
		std::cout << "4. ScavTrap Test" << std::endl;
		std::cout << "5. FragTrap Test" << std::endl;
		std::cout << "6. DiamondTrap Test(NEW!)" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "\nSelect a test > ";
		
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			continue; 
		}

		if (input == 0)
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else if (input == 1)
			test_basics();
		else if (input == 2)
			test_energy();
		else if (input == 3)
			test_death();
		else if (input == 4)
			test_scavtrap();
		else if (input == 5)
			test_fragtrap();
		else if (input == 6)
			test_diamondtrap();
	}
	return (0);
}