/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains the menu functions.
 */
#include <stdio.h>
#include "input.h"
#include "menu.h"
#include "administrator.h"
#include "user.h"
#include "company.h"

int menu(char *msg, int min, int max) {
    printf(msg);
    int option;

    puts(LINE);
    option = getInt(min, max, "Choose your option: ");
    puts(LINE);

    return option;
}

void profile_menu(Companies *companies) {
    int option;


    do {
        option = menu("+------------+\n|Profile menu|\n+------------+\n"
                "(1)-Administrator\n"
                "(2)-User\n"
                "(3)-Company\n"
                "(0)-Exit\n", 0, 3);

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                administrator_menu(companies);
                break;
            case 2:
                consoleClean();
                if ( companies->counter != 0){
                user_menu(companies);
                }else{
                    consoleClean();
                    printf("No available companies to use this menu!\n");
                }
                break;
            case 3:
                consoleClean();
                if ( companies->counter != 0){
                companies_menu(companies);
                }else{
                    consoleClean();
                    printf("No available companies to use this menu!\n");
                }
                
                break;
            default:
                break;

        }
    } while (option != 0);
}

void administrator_menu(Companies *companies) {
    int option;

    do {
        option = menu("+------------------+\n|Administrator Menu|\n+------------------+\n"
                "(1)-Manage companies catalogs\n"
                "(2)-Manage branches of activity\n"
                "(3)-View reports\n"
                "(0)-Exit to Profile Menu\n", 0, 3);

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                manage_catalogs(companies);
                break;
            case 2:
                consoleClean();
                manage_branches(companies);
                break;
            case 3:
                consoleClean();
                if ( companies->counter != 0){
                view_reports(*companies);
                }else{
                    printf("No companies available to use this menu!\n");
                }
                break;
            default:
                break;
        }

    } while (option != 0);
}

void user_menu(Companies *companies) {
    int option;

    do {
        option = menu("+---------+\n|User menu|\n+--------+\n"
                "(1)-Search companies\n"
                "(2)-Classify company\n"
                "(3)-Comment company\n"
                "(0)-Exit to Profile Menu\n", 0, 3);

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                search_companies(*companies);
                break;
            case 2:
                consoleClean();
                classify_company(companies);
                break;
            case 3:
                consoleClean();
                comment_company(companies);
                break;
            default:
                break;

        }
    } while (option != 0);
}

void companies_menu(Companies *companies) {
    int option, company_id;

    company_id = choose_company(*companies);
    list_company(companies->company[company_id], companies->branches);
    do {
        option = menu("+---------+\n|Company menu|\n+--------+\n"
                "(1)-Manage information\n"
                "(2)-View the comments\n"
                "(3)-Analyze research\n"
                "(4)-Average Classification\n"
                "(0)-Exit to Profile Menu\n", 0, 4);

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                manage_information(companies, company_id);
                break;
            case 2:
                consoleClean();
                view_comments(&companies->company[company_id]);
                break;
            case 3:
                consoleClean();
                analyze_research(companies->company[company_id]);
                break;
            case 4:
                consoleClean();
                average_classification(companies->company[company_id]);
                break;
            default:
                break;

        }
    } while (option != 0);
}

void manage_catalogs(Companies *companies) {
    int option;

    do {
        option = menu("+--------------------+\n|Manage Catalogs menu|\n+--------------------+\n"
                "(1)-Create Company\n"
                "(2)-Edit Company\n"
                "(3)-Remove Company\n"
                "(4)-Hide and remove comments\n"
                "(5)-List all companies\n"
                "(0)-Exit to Administrator Menu\n", 0, 5);
        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                create_company(companies);
                break;
            case 2:
                consoleClean();
                edit_company(companies);
                break;
            case 3:
                consoleClean();
                remove_company(companies);
                break;
            case 4:
                consoleClean();
                edit_comments(companies);
                break;
            case 5:
                consoleClean();
                if ( companies->counter != 0){
                    do {
                        list_companies(*companies);
                        printf("\n(1)-List again\n"
                                "(0)- Exit\n");
                        option = getInt(0, 1, "Choose your option: ");
                    } while (option != 0);
                    consoleClean();
                }else {
                    consoleClean();
                    printf("No available companies to list!\n");
                }
                    
                break;
            default:
                break;

        }
    } while (option != 0);

}

void manage_branches(Companies *companies) {
    int option;

    do {
        option = menu("+--------------------+\n|Manage Branches menu|\n+--------------------+\n"
                "(1)-Create\n"
                "(2)-Edit\n"
                "(3)-Remove\n"
                "(0)-Exit to Administrator Menu\n", 0, 3);

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                create_branch(&companies->branches);
                break;
            case 2:
                consoleClean();
                edit_branch(&companies->branches);
                break;
            case 3:
                consoleClean();
                remove_branch(companies);
                break;
            default:
                break;

        }
    } while (option != 0);

}

void average_classification_menu(Companies companies){
    int option, company_id;
    
    do {
        option = menu("+---------------------------+\n|Average classification menu|\n+---------------------------+\n"
                    "(1)-Print all companies average classifications\n"
                    "(2)-Print one company's average classification\n"
                    "(0)-Exit to View Reports\n", 0, 2);
        
        switch (option){
            case 1:
                consoleClean();
                average_classifications(companies);
                break;
            case 2:
                consoleClean();
                company_id = choose_company(companies);
                average_classification(companies.company[company_id]);
                break;
            case 0:
                consoleClean();
                break;
            default:
                break;
        }
    }while (option != 0);
}

void view_reports(Companies companies) {
    int option;

    do {
        
        option = menu("+------------+\n|View reports|\n+------------+\n"
                "(1)-TOP more search\n"
                "(2)-TOP Most comments\n"
                "(3)-Average classification\n"
                "(0)-Exit to Profile Menu\n", 0 , 3);
        

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                topSearch(companies, TOP);
                break;
            case 2:
                consoleClean();
                topComments(companies, TOP);
                break;
            case 3:
                consoleClean();
                average_classification_menu(companies);
                break;
            default:
                break;

        }

    } while (option != 0);
}

void search_companies(Companies companies) {
    int option;

    do {
        option = menu("+----------------+\n|Search Companies|\n+----------------+\n"
                "(1)-Search NIF\n"
                "(2)-Search Category\n"
                "(3)-Search Zip code\n"
                "(0)-Exit to User Menu\n", 0, 3);

        switch (option) {
            case 0:
                consoleClean();
                break;
            case 1:
                consoleClean();
                user_search_nif(companies);
                break;
            case 2:
                consoleClean();
                user_search_category(companies);
                break;
            case 3:
                consoleClean();
                user_search_zipcode(companies);
                break;
            default:
                break;

        }
    } while (option != 0);
}