// Лабораторная работа №5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция просмотра файла
void view_file(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        printf("Error: file not found!\n");
        return;
    }
    
    printf("\n=== File content ===\n");
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        putchar(ch);
    }
    fclose(in);
}

// Функция подсчета символов
void count_characters(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        printf("Error: file not found!\n");
        return;
    }
    
    int total = 0, empty = 0;
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        total++;
        if (isspace(ch) || ch == '\t' || ch == '\n' || ch == '\r') {
            empty++;
        }
    }
    fclose(in);
    
    printf("\n=== Statistics ===\n");
    printf("Total: %d\n", total);
    printf("Empty: %d\n", empty);
    printf("Printable: %d\n", total - empty);
}

// Функция поиска подстроки
void search_substring(const char* filename, const char* substring, const char* result_file) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        printf("Error: file not found!\n");
        return;
    }
    
    FILE* out = fopen(result_file, "w");
    if (out == NULL) {
        printf("Error: cannot create result file!\n");
        fclose(in);
        return;
    }
    
    char line[512];
    int line_num = 0;
    int found = 0;
    int sub_len = strlen(substring);
    
    fprintf(out, "Search for \"%s\" in \"%s\"\n", substring, filename);
    fprintf(out, "===========\n\n");
    
    while (fgets(line, sizeof(line), in) != NULL) {
        line_num++;
        char* pos = line;
        while ((pos = strstr(pos, substring)) != NULL) {
            found++;
            int position = pos - line + 1;
            fprintf(out, "Line %d, pos %d: %s", line_num, position, line);
            pos += sub_len;
        }
    }
    
    if (found == 0) {
        fprintf(out, "Not found.\n");
    } else {
        fprintf(out, "\nTotal: %d\n", found);
    }
    
    fclose(in);
    fclose(out);
    printf("Found %d occurrences. Results saved.\n", found);
}

// Функция шифрования
void encrypt_file(const char* input, const char* output, const char* key) {
    FILE* fin = fopen(input, "rb");
    if (fin == NULL) {
        printf("Error: input file not found!\n");
        return;
    }
    
    FILE* fout = fopen(output, "wb");
    if (fout == NULL) {
        printf("Error: cannot create output file!\n");
        fclose(fin);
        return;
    }
    
    int key_len = strlen(key);
    int key_idx = 0;
    int ch;
    
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key[key_idx % key_len], fout);
        key_idx++;
    }
    
    fclose(fin);
    fclose(fout);
    printf("Processed %d bytes.\n", key_idx);
}

// Функция сравнения файлов
int files_equal(const char* f1, const char* f2) {
    FILE* a = fopen(f1, "rb");
    FILE* b = fopen(f2, "rb");
    
    if (!a || !b) {
        if (a) fclose(a);
        if (b) fclose(b);
        return 0;
    }
    
    int ch1, ch2;
    while ((ch1 = fgetc(a)) != EOF && (ch2 = fgetc(b)) != EOF) {
        if (ch1 != ch2) {
            fclose(a); fclose(b);
            return 0;
        }
    }
    
    int result = (feof(a) && feof(b));
    fclose(a); fclose(b);
    return result;
}

// Главная функция
int main() {
    int choice;
    char filename[256];
    char substring[256];
    char result_file[256];
    char key[256];
    char output_file[256];
    
    do {
        printf("1. View file\n");
        printf("2. Count characters\n");
        printf("3. Search substring\n");
        printf("4. Encrypt/Decrypt file\n");
        printf("5. Test encryption\n");
        printf("0. Exit\n");
        printf("-------------\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                printf("Filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                view_file(filename);
                break;
                
            case 2:
                printf("Filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                count_characters(filename);
                break;
                
            case 3:
                printf("Filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Substring: ");
                fgets(substring, sizeof(substring), stdin);
                substring[strcspn(substring, "\n")] = 0;
                printf("Result file: ");
                fgets(result_file, sizeof(result_file), stdin);
                result_file[strcspn(result_file, "\n")] = 0;
                search_substring(filename, substring, result_file);
                break;
                
            case 4:
                printf("Input file: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Output file: ");
                fgets(output_file, sizeof(output_file), stdin);
                output_file[strcspn(output_file, "\n")] = 0;
                printf("Key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                encrypt_file(filename, output_file, key);
                break;
                
            case 5:
                {
                    printf("\n=== Test ===\n");
                    FILE* t = fopen("test.txt", "w");
                    fprintf(t, "Hello World\n");
                    fprintf(t, "Test line 2\n");
                    fprintf(t, "12345\n");
                    fclose(t);
                    printf("Created test.txt\n");
                    
                    encrypt_file("test.txt", "test.enc", "key123");
                    printf("Encrypted to test.enc\n");
                    
                    encrypt_file("test.enc", "test.dec", "key123");
                    printf("Decrypted to test.dec\n");
                    
                    if (files_equal("test.txt", "test.dec")) {
                        printf("SUCCESS! Files match!\n");
                    } else {
                        printf("ERROR! Files don't match!\n");
                    }
                }
                break;
                
            case 0:
                printf("Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
        
        if (choice != 0) {
            printf("\nPress Enter...");
            getchar();
        }
        
    } while (choice != 0);
    
    return 0;
}