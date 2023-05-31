#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src_file, *dest_file;
    char ch;

    // コマンドライン引数の数が正しいかチェック
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // コピー元ファイルを開く
    src_file = fopen(argv[1], "r");
    if (src_file == NULL) {
        printf("Error opening source file: %s\n", argv[1]);
        return 1;
    }

    // コピー先ファイルを作成
    dest_file = fopen(argv[2], "w");
    if (dest_file == NULL) {
        printf("Error creating destination file: %s\n", argv[2]);
        fclose(src_file);
        return 1;
    }

    // コピー元のファイルから1文字ずつ読み込んでコピー先のファイルに書き込む
    while ((ch = fgetc(src_file)) != EOF) {
        fputc(ch, dest_file);
    }

    // ファイルを閉じる
    fclose(src_file);
    fclose(dest_file);

    printf("File copied successfully.\n");

    return 0;
}
