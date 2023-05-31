#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int recursive = 0;
    int interactive = 0;
    int update = 0;
    int verbose = 0;
    int preserve = 0;
    int link = 0;
    int symbolick = 0;

    int opt;
    while ((opt = getopt(argc, argv, "riuvpls")) != -1) {
        switch (opt) {
            case 'r':
                recursive = 1;
                break;
            case 'i':
                interactive = 1;
                break;
            case 'u':
                update = 1;
                break;
            case 'v':
                verbose = 1;
                break;
            case 'p':
                preserve = 1;
                break;
            case 'l':
                link = 1;
                break;
            case 's':
                symbolick = 1;
                break;
            default:
                fprintf(stderr, "Usage: cp [-r] [-i] [-u] [-v] [-p] [-l] [-s] source_file destination_file\n");
                exit(EXIT_FAILURE);
        }
    }

    int src_index = optind;
    int dest_index = optind + 1;

    char *source_file = argv[src_index];
    char *destination_file = argv[dest_index];

    // ファイルのコピー処理
    FILE *src_file, *dest_file;
    int ch;
    src_file = fopen(source_file, "r");
    if (src_file == NULL) {
        printf("コピー元ファイルを開けませんでした。\n");
        return 1;
    }

    dest_file = fopen(destination_file, "w");
    if (dest_file == NULL) {
        printf("コピー先ファイルを作成できませんでした。\n");
        return 1;
    }

    char buffer[1024];
    size_t bytesRead;
    //１行ごと
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytesRead, dest_file);
    }
    printf("%s",buffer);
    printf("\n");
    printf("%ld",bytesRead);
    printf("\n");
    //文字化けした
    // while (ch = fgetc(src_file) != EOF) {
    //     printf("%d",ch);
    //     fputc(ch, dest_file);
    // }


    fclose(src_file);
    fclose(dest_file);

    printf("Copy options: recursive=%d, interactive=%d, update=%d, verbose=%d, preserve=%d, link=%d, symbolic=%d, \n", recursive, interactive, update, verbose,preserve,link,symbolick);
    printf("Source file: %s\n", source_file);
    printf("Destination file: %s\n", destination_file);

    return 0;
}
