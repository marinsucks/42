/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:29:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/05 11:32:32 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int _contacts_nb;
		int _index;
	public:
		PhoneBook(void);
		void addContact(void);
		void searchContact(void);
		void exitPhoneBook(void);
};

#endif
