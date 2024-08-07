#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void splitName(const char* fullName, char* firstPart, char* lastPart) {
    int len = strlen(fullName);
    int i;

    // Tìm vị trí của khoảng trắng cuối cùng
    int spaceIndex = -1;
    for (i = len - 1; i >= 0; i--) {
        if (fullName[i] == ' ') {
            spaceIndex = i;
            break;
        }
    }

    if (spaceIndex == -1) {
        // Không tìm thấy khoảng trắng, nghĩa là không có họ lót, chỉ có tên
        strcpy(lastPart, fullName);
        firstPart[0] = '\0';
    }
    else {
        // Cắt chuỗi họ lót và tên
        strncpy(firstPart, fullName, spaceIndex);
        firstPart[spaceIndex] = '\0';
        strcpy(lastPart, fullName + spaceIndex + 1);
    }
}

int main() {
    char fullName[] = "Nguyễn Văn Anh";
    char firstPart[100];
    char lastPart[100];

    splitName(fullName, firstPart, lastPart);

    printf("Chuỗi họ lót: \"%s\"\n", firstPart);
    printf("Chuỗi tên: \"%s\"\n", lastPart);

    return 0;
}
