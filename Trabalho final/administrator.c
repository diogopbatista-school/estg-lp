/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains the administrator profile functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "administrator.h"
#include "input.h"

void average_classifications(Companies companies) {
    int i;
    for (i = 0; i < companies.counter; i++) {
        average_classification(companies.company[i]);
    }
}

void list_companies(Companies companies) {
    int i;

    puts(LINE);
    printf("Companies list\n");
    for (i = 0; i < companies.counter; i++) {
        list_company(companies.company[i], companies.branches);
        puts(LINE);
    }
}

void create_company(Companies *companies) {
    int i, verify;

    for (i = 0, verify = 0; i < companies->branches.counter; i++) {
        if (companies->branches.branch[i].branch_state == 1) {
            verify = 1;
            break;
        }
    }
    if (companies->branches.counter != 0 && verify != 0) {
        companies->company[companies->counter].nif = insert_nif(*companies);
        readString(companies->company[companies->counter].name, SIZE, "Insert Company's name: ");
        companies->company[companies->counter].category = getInt(1, 3, "Categories \n"
                "(1)-Micro \n(2)-PME \n(3)-Large \nInsert option: ");
        printf("Branches\n");
        companies->company[companies->counter].branch_activity = select_branch(*companies);
        insert_adress(companies->company[companies->counter].company_adress.street,
                companies->company[companies->counter].company_adress.locality,
                &companies->company[companies->counter].company_adress.postal_code[0],
                &companies->company[companies->counter].company_adress.postal_code[1]);
        companies->company[companies->counter].company_state = 1;
        companies->company[companies->counter].company_comments.counter = 0;
        companies->company[companies->counter].company_class.counter = 0;
        companies->company[companies->counter].nif_search = 0;
        companies->company[companies->counter].category_search = 0;
        companies->company[companies->counter].zip_search = 0;
        companies->company[companies->counter].company_class.classification =
                (Classification*) malloc(sizeof (Classification) * MEMORY_ALLOC);
        companies->company[companies->counter].company_comments.comment =
                (Comment*) malloc(sizeof (Comment) * MEMORY_ALLOC);

        companies->counter++;

        if (companies->counter == sizeof (companies->company) / (int) sizeof (Company)) {
            companies->company = (Company*) realloc(companies->company, companies->counter + MEMORY_ALLOC);
        }

        consoleClean();
    } else {
        consoleClean();
        printf("No branches available to create company!\n");
    }
}

void edit_company(Companies *companies) {
    int option, company_id;
    if (companies->counter != 0) {
        company_id = choose_company(*companies);

        do {
            option = getInt(0, 6, "Edit Company\n"
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
                    readString(companies->company[company_id].name, SIZE, "Insert Company's name");
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
                    if (companies->company[company_id].company_state == 1) {
                        companies->company[company_id].company_state = 0;
                    }else if (companies->company[company_id].company_state == 0) {
                        companies->company[company_id].company_state = 1;
                    }
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        } while (option != 0);
        consoleClean();
    } else {
        consoleClean();
        printf("No available companies to edit!\n");
    }
}

void remove_company(Companies *companies) {
    int company_id, option, i;

    if (companies->counter != 0) {
        company_id = choose_company(*companies);

        option = getInt(1, 2, "Are you sure you want to remove this company? "
                "\n(1)-Yes \n(2)-No \nInsert option: ");
        if (option == 1) {
            if (company_id != companies->counter - 1) {
                if (companies->company[company_id].company_comments.counter != 0) {
                    printf("The company has comments. Changing state to inactive!\n");
                    companies->company[company_id].company_state = 0;
                } else {
                    companies->company[company_id].nif =
                            companies->company[companies->counter - 1].nif;

                    strcpy(companies->company[company_id].name,
                            companies->company[companies->counter - 1].name);

                    companies->company[company_id].branch_activity =
                            companies->company[companies->counter - 1].branch_activity;

                    companies->company[company_id].category =
                            companies->company[companies->counter - 1].category;

                    strcpy(companies->company[company_id].company_adress.street,
                            companies->company[companies->counter - 1].company_adress.street);
                    strcpy(companies->company[company_id].company_adress.locality,
                            companies->company[companies->counter - 1].company_adress.locality);
                    companies->company[company_id].company_adress.postal_code[0] =
                            companies->company[companies->counter].company_adress.postal_code[0];
                    companies->company[company_id].company_adress.postal_code[1] =
                            companies->company[companies->counter].company_adress.postal_code[1];

                    companies->company[company_id].company_state = companies->company[companies->counter - 1].company_state;

                    companies->company[company_id].nif_search =
                            companies->company[companies->counter - 1].nif_search;
                    companies->company[company_id].category_search =
                            companies->company[companies->counter - 1].category_search;
                    companies->company[company_id].zip_search =
                            companies->company[companies->counter - 1].zip_search;

                    for (i = 0; i < companies->company[companies->counter - 1].company_comments.counter; i++) {
                        companies->company[company_id].company_comments.comment[i].comment_state =
                                companies->company[companies->counter - 1].company_comments.comment[i].comment_state;
                        strcpy(companies->company[company_id].company_comments.comment[i].username,
                                companies->company[companies->counter - 1].company_comments.comment[i].username);
                        strcpy(companies->company[company_id].company_comments.comment[i].email,
                                companies->company[companies->counter - 1].company_comments.comment[i].email);
                        strcpy(companies->company[company_id].company_comments.comment[i].title,
                                companies->company[companies->counter - 1].company_comments.comment[i].title);
                        strcpy(companies->company[company_id].company_comments.comment[i].comment,
                                companies->company[companies->counter - 1].company_comments.comment[i].comment);
                    }

                    for (i = 0; i < companies->company[companies->counter].company_class.counter; i++) {
                        strcpy(companies->company[company_id].company_class.classification[i].username,
                                companies->company[companies->counter].company_class.classification[i].username);
                        strcpy(companies->company[company_id].company_class.classification[i].email,
                                companies->company[companies->counter].company_class.classification[i].email);
                        companies->company[company_id].company_class.classification[i].classification =
                                companies->company[companies->counter].company_class.classification[i].classification;
                    }
                    companies->counter--;

                    if (sizeof (companies->company) / (int) sizeof (Company) == companies->counter + MEMORY_ALLOC) {
                        for (i = companies->counter; i < companies->counter + MEMORY_ALLOC; i++) {
                            free(companies->company[i].company_class.classification);
                            free(companies->company[i].company_comments.comment);
                        }
                        companies->company = (Company*) realloc(companies->company,
                                (companies->counter - MEMORY_ALLOC) * sizeof (Company));
                    }
                    printf("The company has been successfully removed!\n");
                }

            } else {
                if (companies->company[company_id].company_comments.counter != 0) {
                    printf("The company has comments. Changing state to inactive!");
                    companies->company[company_id].company_state = 0;
                } else {
                    companies->counter--;
                    free(companies->company[company_id].company_class.classification);
                    free(companies->company[company_id].company_comments.comment);
                }
            }
        } else {
            consoleClean();
        }
    } else {
        consoleClean();
        printf("No available companies to remove!\n");
    }
}

void edit_comments(Companies * companies) {
    int i, company_id, comment_id, option;

    if (companies->counter != 0) {
        company_id = choose_company(*companies);

        if (companies->company[company_id].company_comments.counter != 0) {
            puts(LINE);
            printf("All Comments\n\n");

            for (i = 0; i < companies->company[company_id].company_comments.counter; i++) {
                puts(LINE);
                printf("Comment number: %d\n", i);
                printf("User name: %s\n", companies->company[company_id].company_comments.comment[i].username);
                printf("Title: %s\n", companies->company[company_id].company_comments.comment[i].title);
                printf("Comment: %s\n\n", companies->company[company_id].company_comments.comment[i].comment);
            }

            puts(LINE);
            comment_id = getInt(0, companies->company[company_id].company_comments.counter,
                    "Insert comment's number: ");

            puts(LINE);
            option = getInt(1, 2, "(1)-Change Comment state \n(2)-Remove Comment\nInsert option: ");

            switch (option) {
                case 1:
                    companies->company[company_id].company_comments.comment[comment_id].comment_state =
                            getInt(0, 1, "(0)-Hide \n(1)-Expose \nInsert option: ");
                    consoleClean();
                    break;
                case 2:
                    strcpy(companies->company[company_id].company_comments.
                            comment[comment_id].username,
                            companies->company[company_id].company_comments.
                            comment[companies->company[company_id].company_comments.counter].username);
                    strcpy(companies->company[company_id].company_comments.
                            comment[comment_id].email,
                            companies->company[company_id].company_comments.
                            comment[companies->company[company_id].company_comments.counter].email);
                    strcpy(companies->company[company_id].company_comments.
                            comment[comment_id].title,
                            companies->company[company_id].company_comments.
                            comment[companies->company[company_id].company_comments.counter].title);
                    strcpy(companies->company[company_id].company_comments.
                            comment[comment_id].title,
                            companies->company[company_id].company_comments.
                            comment[companies->company[company_id].company_comments.counter].title);

                    companies->company[company_id].company_comments.counter--;

                    if (companies->company[company_id].company_comments.counter ==
                            (int) sizeof (companies->company[company_id].company_comments.comment) /
                            (int) sizeof (Comment) - MEMORY_ALLOC) {
                        companies->company[company_id].company_comments.comment =
                                (Comment*) realloc(companies->company[company_id].company_comments.comment,
                                sizeof (Comment) * (companies->company[company_id].company_comments.counter - MEMORY_ALLOC));
                    }

                    break;
                default:
                    break;
            }
        } else {
            consoleClean();
            printf("This company has no comments!\n");
        }
    } else {
        consoleClean();
        printf("There are no companies available!\n");
    }
}

void create_branch(Branches * branches) {

    readString(branches->branch[branches->counter].branch_name,
            sizeof (branches->branch[branches->counter].branch_name), "Insert branch name: ");
    branches->branch[branches->counter].branch_state = 1;

    if (branches->counter == sizeof (branches->branch) / (int) sizeof (Branch)) {
        branches->branch = (Branch*) realloc(branches->branch, (sizeof (Branch) * (branches->counter + MEMORY_ALLOC)));
    }
    branches->counter++;
    consoleClean();

}

void edit_branch(Branches * branches) {
    int i, branch_id, option;

    if (branches->counter != 0) {
        printf("Choose the Branch\n");
        for (i = 0; i < branches->counter; i++) {
            puts(LINE);
            printf("Branch's number: %d\n"
                    "Branch's name: %s\n"
                    "Branch's state: %d\n"
                    , i, branches->branch[i].branch_name,
                    branches->branch[i].branch_state);
        }
        puts(LINE);
        branch_id = getInt(0, branches->counter, "Insert the option: ");
        consoleClean();
        do {
            option = getInt(0, 2, "(1)-Change branch name \n(2)- Change branch state\n0- Exit\n");

            switch (option) {
                case 0:
                    break;
                case 1:
                    readString(branches->branch[branch_id].branch_name,
                            sizeof (branches->branch[branch_id].branch_name),
                            "Insert branch new name: ");
                    consoleClean();
                    break;
                case 2:

                    branches->branch[branch_id].branch_state =
                            getInt(0, 1, "New state: \n(0)- Inactive \n(1)- Active "
                            "\nInsert your option: ");
                    consoleClean();
                    break;
                default:
                    break;
            }
        } while (option != 0);
        consoleClean();
    } else {
        consoleClean();
        printf("No available branches to edit!\n");
    }
}

void remove_branch(Companies * companies) {
    int i, branch_id, verify;
    int option = 0;

    if (companies->branches.counter != 0) {
        for (i = 0; i < companies->branches.counter; i++) {
            printf("(%d)- %s \n State: %d\n", i, companies->branches.branch[i].branch_name,
                    companies->branches.branch[i].branch_state);
        }

        branch_id = getInt(0, companies->branches.counter, "Insert your option: ");

        for (i = 0; i < companies->counter; i++) {
            if (companies->company[i].branch_activity == branch_id) {
                verify = 0;
                break;
            }
            verify = 1;
        }

        if (verify == 0) {
            printf("Is not possible to remove the branch?\n");
            option = getInt(1, 2, "Do you want do hide the branch? "
                    "\n(1)-Yes \n(2)-No \nInsert your option: ");

            if (option == 1) {
                companies->branches.branch[branch_id].branch_state = 0;
            }
        } else {
            option = getInt(1, 2, "Are you sure you want to remove this branch? "
                    "\n(1)-Yes \n(2)-No \nInsert your option: ");
            consoleClean();
            if (option == 1) {
                strcpy(companies->branches.branch[branch_id].branch_name,
                        companies->branches.branch[companies->branches.counter - 1].branch_name);
                companies->branches.branch[branch_id].branch_state =
                        companies->branches.branch[companies->branches.counter - 1].branch_state;

                companies->branches.counter--;
                if (companies->branches.counter == (int) sizeof (companies->branches.branch)
                        / (int) sizeof (Branch) - MEMORY_ALLOC) {
                    companies->branches.branch = (Branch*) realloc(companies->branches.branch,
                            sizeof (Branches) * (companies->branches.counter - MEMORY_ALLOC));
                }
            }
        }
        consoleClean();
    } else {
        consoleClean();
        printf("No available branches to remove!\n");
    }
}

void topSearch(Companies companies, int topsearch) {
    int i, j, temp, total_search;
    int company_id[companies.counter], top[companies.counter];

    for (i = 0; i < companies.counter; i++) {
        total_search = companies.company[i].nif_search + companies.company[i].category_search + companies.company[i].zip_search;
        company_id[i] = i;
        top[i] = total_search;
    }

    for (i = 0; i < companies.counter - 1; i++) {
        for (j = 0; j < companies.counter - i - 1; j++) {
            if (top[j] < top[j + 1]) {
                temp = top[j];
                top[j] = top[j + 1];
                top[j + 1] = temp;
                
                temp = company_id[j];
                company_id[j] = company_id[j + 1];
                company_id[j + 1] = temp;
            }
        }
    }
    
    if(companies.counter < topsearch){
        topsearch = companies.counter;
    }
    printf("TOP %d searchs \n", topsearch);
    for (i = 0; i < topsearch; i++) {
        if(companies.company[i].company_state != 0 && top[i] != 0){
            printf("NIF:%d \nName:%s \nNumber of search:%d\n\n",
                companies.company[company_id[i]].nif, companies.company[company_id[i]].name, top[i]);
        }
    }
}

void topComments(Companies companies, int topsearch) {
    int i, j, temp;
    int company_id[companies.counter], top[companies.counter];

    for (i = 0; i < companies.counter; i++) {
        for (j = 0, top[i] = 0; j < companies.company[i].company_comments.counter; j++) {
            if (companies.company[i].company_comments.comment[j].comment_state
                    == 1) {
                top[i]++;
            }
        }
        company_id[i] = i;
    }
    

    for (i = 0; i < companies.counter - 1; i++) {
        for (j = 0; j < companies.counter - i - 1; j++) {
            if (top[j] < top[j + 1]) {
                temp = top[j];
                top[j] = top[j + 1];
                top[j + 1] = temp;
                
                temp = company_id[j];
                company_id[j] = company_id[j + 1];
                company_id[j + 1] = temp;
            }
        }
    }


    if(companies.counter < topsearch){
        topsearch = companies.counter;
    }
    printf("TOP %d comments\n", topsearch);
    for (i = 0; i < topsearch && i < companies.counter; i++) {
        if (companies.company[i].company_state != 0 && top[i] != 0) {
            printf("NIF:%d \nName:%s \n Number of comments:%d\n\n"
                    , companies.company[i].nif, companies.company[i].name, top[i]);
        }
    }
}
