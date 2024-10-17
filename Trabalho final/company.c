/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains the company profile functions.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"
#include "input.h"

void manage_information(Companies *companies, int company_id) {
    int option;

    do {
        option = getInt(0, 5, "Edit Company\n"
                "(1)-NIF \n"
                "(2)-Name \n"
                "(3)-Category \n"
                "(4)-Branch of activity \n"
                "(5)-Adress \n"
                "(6)-State \n"
                "(0)-Exit \n"
                "Insert your option: ");

        switch (option) {
            case 1:
                companies->company[company_id].nif = insert_nif(*companies);
                break;
            case 2:
                readString(companies->company[company_id].name, SIZE, "Insert Company's name: ");
                break;
            case 3:
                companies->company[company_id].category = getInt(1, 3,
                        "Categories \n(1)-Micro \n(2)-PME \n(3)-Large \nInsert option: ");
                break;
            case 4:
                companies->company[company_id].branch_activity = select_branch(*companies);
                break;
            case 5:
                insert_adress(companies->company[company_id].company_adress.street,
                        companies->company[company_id].company_adress.locality,
                        &companies->company[company_id].company_adress.postal_code[0],
                        &companies->company[company_id].company_adress.postal_code[1]);
                break;
            case 6:
                companies->company[company_id].company_state =
                        getInt(0, 1, "(0)-Inactive \n(1)-Active \nInsert state: ");
            case 0:
                break;
            default:
                break;
        }
    } while (option != 0);
}

void view_comments(Company *company) {
    int i, comment_id;

    puts(LINE);
    printf("All Comments \n\n");
    if (company->company_comments.counter == 0) {
        consoleClean();
        printf("This company has no comments\n");
    } else {

        for (i = 0; i < company->company_comments.counter; i++) {
            puts(LINE);
            printf("Comment number: %d\n", i);
            printf("User name: %s\n", company->company_comments.comment[i].username);
            printf("Title: %s\n", company->company_comments.comment[i].title);
            printf("Comment: %s\n", company->company_comments.comment[i].comment);
        }

        puts(LINE);
        comment_id = getInt(0, company->company_comments.counter, "Insert comment's number: ");

        puts(LINE);
        company->company_comments.comment[comment_id].comment_state =
                getInt(0, 1, "(0)-Hide \n(1)-Expose \nInsert option: ");
        consoleClean();

    }
}

void analyze_research(Company company) {
    printf("Your company apeared:\n"
            "%d times on searches by NIF\n"
            "%d times on searches by Category\n"
            "%d times on searches by Zip Code\n", company.nif_search, company.category_search,
            company.zip_search);
}