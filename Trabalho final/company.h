/**
 * 
 * @file company.h
 * @author Utilizador 
 * @date 10-01-2024
 * @version 1
 * 
 * @copyright Copyright (C) Utilizador 2024. All Rights MIT Licensed.
 *
 * @brief A header file providing functionalities for the company menu.
 * 
 * This header file contains declarations and definitions related to company
 * functionality within a program. It includes functions specific for company menu.
 * Users can include this header file to integrate company functionality
 * into their C or C++ programs.
 */

#ifndef COMPANY_H
#define COMPANY_H

#include "utilities.h"

/**
 * @brief This function allows to user to view comments.
 * @param company The company array where all the comments are stored.
 * @return This fuctions does not return a value.
 */
void view_comments(Company *company);
/**
 * @brief This function allows to the company manage the information.
 * @param companies The companies array where is stored all information about the company.
 * @param company_id Is the company ID number.
 * @return This fuction does not return a value.
 */
void manage_information(Companies *companies, int company_id);

/**
 * @brief This function allow the company to analyze research.
 * @param company The company for which research data analysis is performed.
 * @return This function does not return a value.
 */
void analyze_research(Company company);

#endif /* COMPANY_H */



