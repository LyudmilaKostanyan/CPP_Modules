#ifndef DEFINES_HPP
# define DEFINES_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdio>
# include <cstdlib>
#include <cstring>

# define START "Please enter one of three commands - \033[1mADD, SEARCH, EXIT\033[0m: "
# define NAME "Enter contact \033[1mfirst name\033[0m: "
# define L_NAME "Enter contact \033[1mlast name\033[0m: "
# define N_NAME "Enter contact \033[1mnickname\033[0m: "
# define PHONE "Enter contact \033[1mphone number\033[0m: "
# define SECRET "Enter contact \033[1mdarkest secret\033[0m: "
# define W_CMD "\033[1;31mWrong command. Please try again.\033[0m"
# define NAME_ERR "\033[1;31mInput contains invalid characters. Please try again.\033[0m"
# define INDEX "Enter the contact \033[1mindex\033[0m you are looking for: "
# define INDEX_ERR "\033[1;31mIndex out of range. Please try again in range (0, 7).\033[0m"

bool	get_input(std::string *, const char *);

#endif