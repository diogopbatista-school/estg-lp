/**
 * 
 * @file menu.h
 * @author Utilizador
 * @date 30-11-2023
 * @version 1
 * 
 * @copyright Copyright (C) Utilizador 2023. All Rights MIT Licensed.
 * 
 * @brief A header file providing menu functions in a program.
 * 
 * This header file contains declarations and definitions related to menu
 * functionality within a program. It includes functions and structures specific
 * to the features available in menu.
 * Users can include this header file to integrate Menufunctionality
 * into their C or C++ programs.
 */

#ifndef MENU_H
#define MENU_H

#include "utilities.h"

/**
 * @brief 
 * @param msg A custom message to prompt the user for input.
 * @param min The minimum valid integer value.
 * @param max The maximum valid integer value.
 * @return The user-provided menu.
 */
int menu(char *msg, int min, int max);

/**
 * @brief This function shows the options to choose between user and administrator.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the address of the Companies structure to subsequent functions.
 * @return This function does not return a value. It only shows the options.
 */
void profile_menu(Companies *companies);

/**
 * @brief This function shows the managing options to the administrator.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the address of the Companies structure to subsequent functions.
 * @return This function does not return a value. It guides the administrator
 * through the main menu options and redirects to the corresponding
 * functions based on their choices.
 */
void administrator_menu(Companies *companies);

/**
 * @brief This function show the companies catalogs management options to the administrator.
 * @param companies the companies array where the information about the companies
 *  will be managed.
 * @return This function does not return a value. It guides the administrator 
 * through the catalogs management process and redirects to the corresponding 
 * actions based on their choices.
 */
void manage_catalogs(Companies *companies);

/**
 * @brief This function shows the branches of activity management options to the administrator.
 * @param companies The companies array where the information about the branches
 * will be managed.
 * @return This function does not return a value. It guides the administrator 
 * through the branches management process and redirects to the corresponding 
 * actions based on their choices.
 */
void manage_branches(Companies *companies);

/**
 * @brief This function shows the average classification options to the administrator. 
 * @param companies The companies array where is containing information about
 * the companies in the system.
 * @return This function does not return a value. It guides the administrator
 * through the average classification-related actions and redirects
 * to the corresponding functions based on their choices.
 */
void average_classification_menu(Companies companies);

/**
 * @brief This function show the viewing reports options to the administrator.
 * @param companies The companies array where is containing information about
 * the companies in the system.
 * @return This function does not return a value. It guides the administrator
 * through the reports options and redirects to the corresponding functions 
 * based on their choices.
 */
void view_reports(Companies companies);

/**
 * @brief This function shows sereval options to the user to choose.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the address of the Companies structure to subsequent functions.
 * @return This function does not return a value. It guides the user through the 
 * main menu options and redirects to the corresponding functions based on their
 * choices.  
 */
void user_menu(Companies *companies);

/**
 * @brief This function allows the user to find companies.
 * @param companies The companies array where is containing information about
 * the companies in the system.
 * @return This function does not return a value. It guides the user through
 * the company search options and displays the results based on their specified
 * criteria.
 */
void search_companies(Companies companies);

/**
 * @brief This function shows sereval options to the company to choose.
 * @param companies A pointer to the main variable "companies" that is used to
 * pass the adress of Companies structure to subsequent functions.
 * @return This function does not return a value. It guides the company through 
 * the main menu options and redirects to the corresponding functions based on 
 * their choices. 
 */
void companies_menu(Companies *companies);

#endif /* MENU_H */