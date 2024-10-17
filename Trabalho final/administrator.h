/**
 * 
 * @file administrator.h
 * @author Utilizador
 * @date 10-01-2024
 * @version 1
 * 
 * @copyright Copyright (C) Utilizador 2024. All Rights MIT Licensed.
 * 
 * @brief A header file providing functionalities for the administrator menu.
 * 
 * This header file contains declarations and definitions related to administrator
 * functionality within a program. It includes functions to the features available 
 * for administrator.
 * Users can include this header file to integrate administrator functionality
 * into their C or C++ programs.
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "utilities.h"

/**
 * @brief This function list all companies.
 * @param companies The companies array where the information about all companies is stored.
 * @return This function does not return a value. It shows the list of companies.
 */
void list_companies(Companies companies);

/**
 * @brief This function allows to administrator create a company.
 * @param companies The companies array where the new company will be added.
 * @return company created provided by the user.
 */
void create_company(Companies *companies);

/**
 * @brief This function allows to administrator to edit a company.
 * @param companies The companies array where the company to be edit is stored.
 * @return This fuction does not return a value.
 */
void edit_company(Companies *companies);

/**
 * @brief This function allows to administrator to remove a company.
 * @param companies The companies array where the company is stored will be removed.
 * @return This fuction does not return a value.
 */
void remove_company(Companies *companies);

/**
 * @brief This function allows to adimistrator to create branches.
 * @param branches The branches array where the new branch will be added.
 * @return This function does not return a value.
 */
void create_branch(Branches *branches);

/**
 * @brief This function allows to administrator to edit a branch.
 * @param branches The branches array where the branch to be edit is stored.
 * @return This fuction does not return a value.
 */
void edit_branch(Branches *branches);

/**
 * @brief This function allows to administrator to remove a branch.
 * @param companies The companies array where the branch to be removed is stored.
 * @return this fuctions does not return a value.
 */
void remove_branch(Companies *companies);

/**
 * @brief This function allows to administrator to edit comments.
 * @param companies The companies array where the comment to be edit is stored.
 * @return This fuction does not return a value.
 */
void edit_comments(Companies *companies);

/**
 * @brief This function shows the average classification of the all companies.
 * @param companies The companies arrary where average classifications is stored.
 * @return This function does not return a value. 
 */
void average_classifications(Companies companies);

/**
 * @brief This function allows to the user to see the top search.
 * @param companies The list of companies from which to retrieve top search results. 
 * @param topsearch The number of top search results to retrieve and display.
 * @return This fuction does not return a value .
 */
void topSearch(Companies companies, int topsearch);

/**
 * @brief This function allows to user to see wich company has the most comments.
 * @param companies The list of companies from wich to retrieve top search results.
 * @param topsearch The number of top search results to retrieve and display.
 * @return This fuction does not return a value.
 */
void topComments(Companies companies, int topsearch);
#endif /* ADMINISTRATOR_H */

