/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains the user profile functions.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "input.h"

void user_search_nif(Companies companies) {
    int company_id, option;

    if (companies.counter != 0) {
        company_id = choose_company(companies);

        if (companies.company[company_id].company_state != 1) {
            consoleClean();
            printf("The company does not exist!\n");
            return;
        }
        do {
            consoleClean();
            list_company(companies.company[company_id], companies.branches);
            printf("\n(1)- List again\n"
                    "(0)- Exit\n");
            option = getInt(0, 1, "Choose your option: ");
        } while (option != 0);
        consoleClean();
        companies.company[company_id].nif_search++;

    } else {
        consoleClean();
        printf("No available companies to search!\n");
    }
}

void user_search_category(Companies companies) {
    int option;
    int i;

    option = getInt(1, 3, "Categories \n"
            "(1)-Micro \n(2)-PME \n(3)-Large \nInsert option: ");

    for (i = 0; i < companies.counter; i++) {
        if (option == companies.company[i].category
                && companies.company[i].company_state == 1) {

            list_company(companies.company[i], companies.branches);
            companies.company[i].category_search++;

        }
    }
}

void user_search_zipcode(Companies companies) {
    int zipcode1;
    int zipcode2;
    int i, option;

    zipcode1 = getInt(1000, 9999, "Insert postal code's first part: ");
    zipcode2 = getInt(100, 999, "Insert postal code's second part: ");
    do {
        for (i = 0; i < companies.counter; i++) {
            if (zipcode1 == companies.company[i].company_adress.postal_code[0] &&
                    zipcode2 == companies.company[i].company_adress.postal_code[1]
                    && companies.company[i].company_state == 1) {

                list_company(companies.company[i], companies.branches);
                companies.company[i].zip_search++;
                return;
            }
        }

        printf("\n(1)- List again\n"
                    "(0)- Exit\n");
        option = getInt(0, 1, "Choose your option: ");
    } while (option != 0);
}

void classify_company(Companies *companies) {
    int company_id;

    company_id = choose_company(*companies);
    if (companies->company[company_id].company_state != 1) {
        printf("This company does not exist!");
        return;
    }

    readString(companies->company[company_id].company_class.
            classification[companies->company[company_id].company_class.counter].username,
            sizeof (companies->company[company_id].company_class.
            classification[companies->company[company_id].company_class.counter].username),
            "Insert username: ");
    readString(companies->company[company_id].company_class.
            classification[companies->company[company_id].company_class.counter].email,
            sizeof (companies->company[company_id].company_class.
            classification[companies->company[company_id].company_class.counter].email),
            "Insert email: ");

    companies->company[company_id].company_class.
            classification[companies->company[company_id].company_class.counter].classification =
            getFloat(0.0, 5.0, "Classification (0.0 - 5.0): ");
    companies->company[company_id].company_class.counter++;

    if (companies->company[company_id].company_class.counter ==
            sizeof (companies->company[company_id].company_class.classification) /
            (int) sizeof (Classification)) {
        companies->company[company_id].company_class.classification =
                (Classification*) realloc(companies->company[company_id].
                company_class.classification, sizeof (Classification) *
                (companies->company[company_id].company_class.counter + MEMORY_ALLOC));
    }
    consoleClean();
}

void comment_company(Companies *companies) {
    int company_id;

    company_id = choose_company(*companies);
    if (companies->company[company_id].company_state != 1) {
        printf("This company does not exist!");
        return;
    }
    readString(companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].username,
            sizeof (companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].username),
            "Insert username: ");
    readString(companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].email,
            sizeof (companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].email),
            "Insert email: ");
    readString(companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].title,
            sizeof (companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].title),
            "Insert title: ");
    readString(companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].comment,
            sizeof (companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].comment),
            "Insert comment: ");

    companies->company[company_id].company_comments.
            comment[companies->company[company_id].company_comments.counter].comment_state = 1;

    companies->company[company_id].company_comments.counter++;

    if (companies->company[company_id].company_comments.counter ==
            sizeof (companies->company[company_id].company_comments.comment)
            / (int) sizeof (Comment)) {
        companies->company[company_id].company_comments.comment =
                (Comment*) realloc(companies->company[company_id].company_comments.comment,
                sizeof (Comment) * (companies->company[company_id].company_comments.counter + MEMORY_ALLOC));
    }
    consoleClean();
}