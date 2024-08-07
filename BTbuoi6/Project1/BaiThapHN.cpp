#include <stdio.h>

// Hàm để di chuyển đĩa từ cột nguồn sang cột đích
void MoveDisk(char from, char to) {
    printf("Di chuyển đĩa từ %c đến %c\n", from, to);
}

// Hàm đệ quy để giải bài toán Tháp Hà Nội
void Tower(int n, char colA, char colB, char colC) {
    if (n == 1) {
        // Nếu chỉ có 1 đĩa, chuyển từ cột nguồn đến cột đích
        MoveDisk(colA, colC);
    }
    else {
        // Chuyển n - 1 đĩa từ cột nguồn sang cột trung gian
        Tower(n - 1, colA, colC, colB);

        // Chuyển đĩa thứ n từ cột nguồn đến cột đích
        MoveDisk(colA, colC);

        // Chuyển n - 1 đĩa từ cột trung gian đến cột đích
        Tower(n - 1, colB, colA, colC);
    }
}

int main() {
    int n;
    printf("Nhập số lượng đĩa: ");
    scanf("%d", &n);

    // Khởi tạo bài toán với 3 cột A, B và C
    Tower(n, 'A', 'B', 'C');

    return 0;
}
