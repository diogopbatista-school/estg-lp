/**
 * 
 * @file data.h
 * @author Utilizador
 * @date 09-01-2024
 * @version 1
 * 
 * @copyright Copyright (C) Utilizador 2024. All Rights MIT Licensed.
 * 
 * @brief A header file providing utility functions for file loading and saving.
 * 
 * This header file contains functions designed to assist users in handling files
 * within C or C++ programs. It includes functions for loading and saving files.
 * Users can use these functions to interact with external files and manage
 * data storage and retrieval.
 */
#ifndef DATA_H
#define DATA_H


/**
 * @brief This function allows to user to load files.
 * @param companies Used to send the adress of the main variable "companies" to the following functions.
 * @return This function does not return any value.
 */
void load_file(Companies *companies);
/**
 * @brief This function allows to the user to save files.
 * @param companies Used to send the adress of the main variable " companies" to the following functions.
 * @return This function does not return any value.
 */
void save_file(Companies *companies);

#endif /* DATA_H */

