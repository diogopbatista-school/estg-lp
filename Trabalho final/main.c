/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains the main function of the program.
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"
#include "utilities.h"
#include "data.h"


int main () {
    Companies companies;
    int option, i;
    
    
    
    companies.company = (Company*) malloc(sizeof (Company) * MEMORY_ALLOC);
    companies.branches.branch = (Branch*) malloc(sizeof (Branch) * MEMORY_ALLOC);

    companies.counter = 0;
    companies.branches.counter = 0;
    if (companies.company != NULL && companies.branches.branch!= NULL) {
        do {
            option = menu("+---------+\n|Main Menu|\n+---------+\n"
                    "(1)-Profile menu \n"
                    "(2)-Load file \n"
                    "(3)-Save file \n"
                    "(0)-Exit \n", 0, 3);

            switch (option) {
                case 1:
                    consoleClean();
                    profile_menu(&companies);
                    break;
                case 2:
                    consoleClean();
                    load_file(&companies);
                    break;
                case 3:
                    consoleClean();
                    save_file(&companies);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

        } while (option != 0);

        free(companies.branches.branch);
        for (i = 0; i < companies.counter; i++) {
            free(companies.company[i].company_class.classification);
            free(companies.company[i].company_comments.comment);
        }
        free(companies.company);
        return 0;
    }
    printf("ERROR!\n");
    return 1;
}



