/**
 * 
 * @file utilities.h
 * @author Utilizador
 * @date 10-01-2024
 * @version 1
 * 
 * @copyright Copyright (C) Utilizador 2024. All Rights MIT Licensed.
 * 
 * @brief Header file containing data structures and function prototypes that 
 * can be used throughout the program.
 * 
 * This header file defines various data structures and functions essential for
 * managing company information.
 * It includes structures for addresses, comments, branches, classifications, 
 * companies, and functions for user interactions such as entering information, 
 * listing companies, and calculating average classifications.
*/
#ifndef UTILITIES_H
#define UTILITIES_H

#define  LINE         "+------------------------------------------------------+"
#define  SIZE            50
#define  SIZE_COMMENT    500
#define  MEMORY_ALLOC    5
#define  TOP             5

typedef struct {
    char street[SIZE];
    char locality[SIZE];
    int postal_code[2];
} Adress;

typedef struct {
    char username[SIZE];
    char email[SIZE];
    char title[SIZE];
    char comment[SIZE_COMMENT];
    int comment_state;
} Comment;

typedef struct {
    int counter;
    Comment *comment;
} Comments;

typedef struct {
    char branch_name[SIZE];
    int branch_state;
} Branch;

typedef struct {
    int counter;
    Branch *branch;
} Branches;

typedef struct {
    char username[SIZE];
    char email[SIZE];
    float classification;
} Classification;

typedef struct {
    int counter;
    Classification *classification;
} Classifications;

typedef struct {
    int nif;
    char name[SIZE];
    int category;
    int branch_activity;
    int company_state;
    int nif_search, category_search, zip_search;
    Adress company_adress;
    Comments company_comments;
    Classifications company_class;
} Company;

typedef struct {
    int counter;
    Branches branches;
    Company *company;
} Companies;

/**
 * @brief This function is used to enter the NIF.
 * @param companies The companies array where the nif will be added.
 * @return The user-provided NIF.
 */
int insert_nif(Companies companies);

/**
 * @brief This function is used to enter the branch.
 * @param companies The companies array where the information about the branch is containing.
 * @return The user-provided branch.
 */
int select_branch(Companies companies);

/**
 * @brief This function is used to enter the NIF.
 * @param street A character array to store the user-provided street name.
 * @param locality A character array to store the user-provided locatity.
 * @param pc1 A numbers array to store the user-provided the first part of zipcode.
 * @param pc2 A numbers array to store the user-provided the second part of zipcode.
 * @return This fuction does not return a value.
 */
void insert_adress(char *street, char *locality, int *pc1, int *pc2);

/**
 * @brief This fuction allows to the users list one company
 * @param company The company to be listed.
 * @param branches The branches array where the information about the branch of the company is stored.
 * @return This function does not return a value. 
 */
void list_company(Company company, Branches branches);

/**
 * @brief This function allows to administrator to choose a company.
 * @param companies The companies array where the information about all companies is stored.
 * @return company choice provided by the user.
 */
int choose_company(Companies companies);

/**
 * @brief This function allows the user to caculate the average classification.
 * @param array The array where the classification will be added.
 * @param total The total of the classifications.
 * @return The average classification.
 */
float average(Classification *array,int total);

/**
 * @brief This function shows the average classification of the company.
 * @param company The company for which to calculate the average classification.
 * @return This function does not return a value. 
 */
void average_classification(Company company);


#endif /* UTILITIES_H */

