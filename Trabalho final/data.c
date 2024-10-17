/**
 * @file input.c
 * @author ESTG
 * @date 12-01-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains the file management functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"
#include "company.h"

#define FILENAME "companies.bin"

void load_file(Companies *companies){
    int i, j;
    FILE *file;
    
    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }
    if (file != NULL) {
        printf("File was opened successfully! \n");

        fread(&(companies->counter), sizeof (int), 1, file);
        companies->company = (Company*) realloc(companies->company,
                (companies->counter + 5) * sizeof (Company));

        fread(&companies->branches.counter, sizeof (int), 1, file);
        companies->branches.branch = (Branch*)
                realloc(companies->branches.branch,
                (companies->branches.counter + 5) * sizeof (Branch));
        for (i = 0; i < companies->branches.counter; i++) {

            fread(&companies->branches.branch[i], sizeof (Branch)
                    , 1, file);
        }

        for (i = 0; i < companies->counter; i++) {
            fread(&companies->company[i].nif, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].name, sizeof (char)
                    , SIZE, file);
            fread(&companies->company[i].category, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].branch_activity, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].company_state, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].nif_search, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].category_search, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].zip_search, sizeof (int)
                    , 1, file);
            fread(&companies->company[i].company_adress
                    , sizeof (Adress), 1, file);

            fread(&companies->company[i].company_comments.counter
                    ,sizeof (int), 1, file);
            companies->company[i].company_comments.comment = (Comment*)
                    malloc((companies->company[i].company_comments.counter + MEMORY_ALLOC)
                    * sizeof (Comment));
            for (j = 0; j < companies->company[i].company_comments.counter
                    ; j++) {
                fread(&companies->company[i].company_comments.comment[j]
                        , sizeof (Comment), 1, file);
            }

            fread(&companies->company[i].company_class.counter
                    ,sizeof(int), 1, file);
            companies->company[i].company_class.classification = (Classification*)
                    malloc((companies->company[i].company_class.counter + MEMORY_ALLOC)
                    * sizeof (Classification));

            for (j = 0; j < companies->company[i].company_class.counter; j++) {
                fread(&companies->company[i].company_class.classification[j],
                        sizeof (Classification), 1, file);
            }
        }
    }

    fclose(file);
}

void save_file(Companies *companies){
    int i, j;
    FILE *file;
    
    file = fopen(FILENAME, "wb+");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }
    if (file != NULL) {
        printf("The file was saved successfully!\n");
        fwrite(&companies->counter, sizeof (int), 1, file);

        fwrite(&companies->branches.counter, sizeof (int), 1, file);

        for (i = 0; i < companies->branches.counter; i++) {

            fwrite(&companies->branches.branch[i], sizeof (Branch)
                    , 1, file);
        }

        for (i = 0; i < companies->counter; i++) {
            fwrite(&companies->company[i].nif, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].name, sizeof (char)
                    , SIZE, file);
            fwrite(&companies->company[i].category, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].branch_activity, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].company_state, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].nif_search, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].category_search, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].zip_search, sizeof (int)
                    , 1, file);
            fwrite(&companies->company[i].company_adress
                    , sizeof (Adress), 1, file);

            fwrite(&companies->company[i].company_comments.counter
                    , sizeof (int), 1, file);


            for (j = 0; j < companies->company[i].company_comments.counter
                    ; j++) {
                fwrite(&companies->company[i].company_comments.comment[j]
                        , sizeof (Comment), 1, file);
            }

            fwrite(&companies->company[i].company_class.counter,
                    sizeof (int), 1, file);
            for (j = 0; j < companies->company[i].company_class.counter; j++) {
                fwrite(&companies->company[i].company_class.classification[j],
                        sizeof (Classification), 1, file);
            }
        }
    }
    fclose(file);

}