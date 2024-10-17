/**
 * 
 * @file user.h
 * @author Utilizador
 * @date 10-01-2024
 * @version 1
 * 
 * @copyright Copyright (C) Utilizador 2024. All Rights MIT Licensed.
 * 
 * 
 * @brief A header file providing functionalities for the user menu.
 * 
 * This header file contains declarations and definitions related to the user 
 * menu within a program. It function prototypes for user interactions like entering
 * company information, searching by NIF or category, classifying, and commenting on companies.
 * Users can include this header file to integrate company management functionality
 * into their C or C++ programs.
 */

#ifndef USER_H
#define USER_H

#include "utilities.h"

/**
 * @brief This function allows to user to search the NIF.
 * @param companies The companies array containing information about the NIF of the companies.
 * @return This fuction does not return a value.
 */
void user_search_nif(Companies companies);

/**
 * @brief This function allows to user to search a category.
 * @param companies The companies array containing information about the category of the companies.
 * @return This fuction does not return a value.
 */
void user_search_category(Companies companies);

/**
 * @brief This function allows to user to search zipcode.
 * @param companies The companies array contaning information about the zipcode of the companies.
 * @return This fuction does not return a value.
 */
void user_search_zipcode(Companies companies);

/**
 * @brief This function allows to user to classify a company.
 * @param companies the companies array where the classification will be added.
 * @return This function does not return a value.
 */
void classify_company(Companies *companies);

/**
 * @brief This function allows to user to comment a company.
 * @param companies The companies array where the comment will be added.
 * @return This fuction does not return a value.
 */
void comment_company(Companies *companies);

#endif /* USER_H */

