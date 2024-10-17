/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains utility functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"
#include "input.h"


int insert_nif(Companies companies) {
    int i;
    int check = 1;
    int nif;

    do {
        nif = getInt(100000000, 999999999, "Insert NIF: ");
        for (i = 0; i < companies.counter; i++) {
            if (nif == companies.company[i].nif) {
                check = 0;
                consoleClean();
                printf("NIF already exists!\n");
                break;
            } else {
                check = 1;
            }

        }
    } while (check == 0);

    return nif;
}

int select_branch(Companies companies) {
    int i, branch;
    do {
        for (i = 0; i < companies.branches.counter; i++) {
            if (companies.branches.branch[i].branch_state == 1) {
                printf("(%d) - %s\n", i, companies.branches.branch[i].branch_name);

            }
        }

        branch = getInt(0, companies.branches.counter, "Insert the Branch Ativity: ");
    } while (companies.branches.branch[branch].branch_state == 0);
    return branch;
}

void insert_adress(char *street, char *locality, int *pc1, int *pc2) {
    readString(street, SIZE, "Insert company's street: ");
    readString(locality, SIZE, "Insert company's locality: ");
    *pc1 = getInt(1000, 9999, "Insert postal code's first part: ");
    *pc2 = getInt(100, 999, "Insert postal code's second part: ");
}

void list_company(Company company, Branches branches) {
    char *category;

    switch (company.category) {
        case 1:
            category = "Micro";
            break;
        case 2:
            category = "PME";
            break;
        case 3:
            category = "Large";

            break;
        default:
            break;
    }
    puts(LINE);
    printf("NIF: %d \nName: %s \nCategory: %s \nBranch: %s \n\nAdress\nStreet: %s "
            "\nLocality: %s \nZip Code:%d-%d\n\nNumber of comments: %d \n", company.nif, company.name, category, branches.branch[company.branch_activity].branch_name,
            company.company_adress.street, company.company_adress.locality,
            company.company_adress.postal_code[0], company.company_adress.postal_code[1],
            company.company_comments.counter);
    if (company.company_class.counter > 0) {
        printf("Average Classification: %.2f \nState(0-Inactive,1-Active): %d\n\n",
                average(company.company_class.classification, company.company_class.counter),
                company.company_state);
    } else {
        printf("Average Classification: No Classifications \nState(0-Inactive,1-Active): %d\n\n",
                company.company_state);
    }
    puts(LINE);
}

int choose_company(Companies companies) {
    int i, company_id, nif;
    do {
        nif = getInt(100000000, 999999999, "Insert Company's NIF: ");

        for (i = 0; i < companies.counter; i++) {
            if (companies.company[i].nif == nif) {
                company_id = i;
                break;
            } else {
                company_id = -1;
            }
        }

        if (company_id == -1) {
            printf("There is no company with this NIF!\n");
        }

    } while (company_id == -1);
    return company_id;
}

float average(Classification *array, int total) {
    int i;
    float sum = 0;

    for (i = 0; i < total; i++) {
        sum += array[i].classification;
    }

    return sum / total;
}

void average_classification(Company company) {
    printf("Company's NIF: %d \nCompany's name: %s \n",
            company.nif, company.name);
    if (company.company_class.counter > 0) {
        printf("Classification: %.2f \n",
                average(company.company_class.classification, company.company_class.counter));
    } else {
        printf("Classification: No Classifications \n");
    }
}