/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relevant_name.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 09:46:45 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 09:46:46 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "relevant_header.hpp"

int D_SIZE = 8;
static int I = 0;

void display_opt()
{
  std::cout << "What do you want to do?\n\
  ADD THINGS TO THE THING     =~ ADD\n\
  DO I LOOK LIKE YOUR MOTHER? =~ SEARCH\n\
  BYE                         =~ EXIT\n\
  HELP ME I NEED AN ADULT     =~ HELP"
  << std::endl;
  return ;
}

Relevant_data::Relevant_data()
{
  return ;
}

Relevant_data::~Relevant_data(void)
{
  return ;
}

void add(Relevant_data data, Relevant_data *p)
{
  if (I >= D_SIZE)
  {
    std::cout << "database full\n";
    return ;
  }
  std::cout << "First Name\n";
  std::getline (std::cin, data.first_name);
  std::cout << "Last Name\n";
  std::getline (std::cin, data.last_name);
  std::cout << "Nick Name\n";
  std::getline (std::cin, data.nickname);
  std::cout << "Login\n";
  std::getline (std::cin, data.login);
  std::cout << "Postal Address\n";
  std::getline (std::cin, data.postal_address);
  std::cout << "Email Address\n";
  std::getline (std::cin, data.email_address);
  std::cout << "Phone #\n";
  std::getline (std::cin, data.phone_number);
  std::cout << "Birthday\n";
  std::getline (std::cin, data.birthday_date);
  std::cout << "Favorite Meal\n";
  std::getline (std::cin, data.favorite_meal);
  std::cout << "Underwear Color\n";
  std::getline (std::cin, data.underwear_color);
  std::cout << "Darkest Secret\n";
  std::getline (std::cin, data.darkest_secret);
  data.empty = 1;
  data.index = I;
  I += 1;
  p[data.index] = data;
  std::cout.clear();
  std::cin.clear();
  return ;
}

void search(Relevant_data *p)
{
  int i;
  int j;


  for (i = 0; p[i].empty; i++)
  {
    std::cout << "         " << i << "|";
    if ((int)p[i].first_name.length() < 10)
    {
      for (j = 0; j < 10 - (int)p[i].first_name.length(); j++)
        std::cout << " ";
      std::cout << p[i].first_name;
    }
    else if ((int)p[i].first_name.length() > 10)
    {
      std::cout << p[i].first_name.substr(0, 9);
      std::cout << ".";
    }
    else
    {
      std::cout << p[i].first_name;
    }
    std::cout << "|";
    if ((int)p[i].last_name.length() < 10)
    {
      for (j = 0; j < 10 - (int)p[i].last_name.length(); j++)
        std::cout << " ";
      std::cout << p[i].last_name;
    }
    else if ((int)p[i].last_name.length() > 10)
    {
      std::cout << p[i].last_name.substr(0, 9);
      std::cout << ".";
    }
    else
    {
      std::cout << p[i].last_name;
    }
    std::cout << "|";
    if ((int)p[i].nickname.length() < 10)
    {
      for (j = 0; j < 10 - (int)p[i].nickname.length(); j++)
        std::cout << " ";
      std::cout << p[i].nickname;
    }
    else if ((int)p[i].nickname.length() > 10)
    {
      std::cout << p[i].nickname.substr(0, 9);
      std::cout << ".";
    }
    else
    {
      std::cout << p[i].nickname;
    }
    std::cout << std::endl;
  }

  std::cout << "what index do u want lol\n";
  std::cin >> i;
  if (!std::cin.good())
  {
    std::cout << "that doesn't work\n";
    std::cin.ignore(INT_MAX, '\n');
    return ;
  }
  if (!p[i].empty)
  {
    std::cout << "user doesn't exist\n";
    std::cin.ignore(INT_MAX, '\n');
    return ;
  }

  std::cout << "         " << i << "|";
  if ((int)p[i].first_name.length() < 10)
  {
    for (j = 0; j < 10 - (int)p[i].first_name.length(); j++)
      std::cout << " ";
    std::cout << p[i].first_name;
  }
  else if ((int)p[i].first_name.length() > 10)
  {
    std::cout << p[i].first_name.substr(0, 9);
    std::cout << ".";
  }
  else
  {
    std::cout << p[i].first_name;
  }
  std::cout << "|";
  if ((int)p[i].last_name.length() < 10)
  {
    for (j = 0; j < 10 - (int)p[i].last_name.length(); j++)
      std::cout << " ";
    std::cout << p[i].last_name;
  }
  else if ((int)p[i].last_name.length() > 10)
  {
    std::cout << p[i].last_name.substr(0, 9);
    std::cout << ".";
  }
  else
  {
    std::cout << p[i].last_name;
  }
  std::cout << "|";
  if ((int)p[i].nickname.length() < 10)
  {
    for (j = 0; j < 10 - (int)p[i].nickname.length(); j++)
      std::cout << " ";
    std::cout << p[i].nickname;
  }
  else if ((int)p[i].nickname.length() > 10)
  {
    std::cout << p[i].nickname.substr(0, 9);
    std::cout << ".";
  }
  else
  {
    std::cout << p[i].nickname;
  }
  std::cout << std::endl;
  std::cin.ignore(INT_MAX, '\n');
  return ;
}

int main(void)
{
  std::string option;
  Relevant_data *p = new Relevant_data[D_SIZE];
  while (1)
  {
    display_opt();
    std::getline (std::cin, option);
    if (!option.compare("ADD"))
    {
      Relevant_data d;
      add(d, p);
    }
    else if (!option.compare("SEARCH"))
    {
      search(p);
    }
    else if (!option.compare("EXIT"))
    {
      std::cout << "see ya\n";
      break ;
    }

  }
  return (0);
}
