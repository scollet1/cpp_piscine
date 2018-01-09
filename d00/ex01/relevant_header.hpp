/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relevant_header.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:07:57 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 10:07:58 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Relevant_data {

public:
  Relevant_data(void);
	~Relevant_data(void);

  int empty;
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string login;
  std::string postal_address;
  std::string email_address;
  std::string phone_number;
  std::string birthday_date;
  std::string favorite_meal;
  std::string underwear_color;
  std::string darkest_secret;
  int index;
};
