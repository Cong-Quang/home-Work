#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 2000
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct Contact {
    char hoVaTen[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact danhBa[MAX_CONTACTS];
int soLuongContacts = 0;

void themContact() {
    if (soLuongContacts >= MAX_CONTACTS) {
        printf("Danh ba da day, khong the them moi.\n");
        return;
    }

    printf("Nhap ten: ");
    scanf("%s", danhBa[soLuongContacts].hoVaTen);
    printf("Nhap so dien thoai: ");
    scanf("%s", danhBa[soLuongContacts].phoneNumber);
    printf("Nhap email: ");
    scanf("%s", danhBa[soLuongContacts].email);

    soLuongContacts++;
    printf("Da them contact thanh cong.\n");
}

void timKiemContact() {
    char search[MAX_NAME_LENGTH];
    printf("Nhap ten, so dien thoai hoac email can tim: ");
    scanf("%s", search);

    printf("                    Ket qua tim kiem\n");
    for (int i = 0; i < soLuongContacts; i++) {
        if (strstr(danhBa[i].hoVaTen, search) || strstr(danhBa[i].phoneNumber, search) || strstr(danhBa[i].email, search)) {
            printf("Ho va ten: %s\n", danhBa[i].hoVaTen);
            printf("So dien thoai: %s\n", danhBa[i].phoneNumber);
            printf("Email: %s\n", danhBa[i].email);
        }
    }
    printf("                    Ket qua tim kiem\n");
}

void xoaContact() {
    char search[MAX_NAME_LENGTH];
    printf("Nhap ten, so dien thoai hoac email cua contact can xoa: ");
    scanf("%s", search);

    int found = 0;
    for (int i = 0; i < soLuongContacts; i++) {
        if (strstr(danhBa[i].hoVaTen, search) || strstr(danhBa[i].phoneNumber, search) || strstr(danhBa[i].email, search)) {
            found = 1;
            printf("Contact da tim thay:\n");
            printf("Ho va ten: %s\n", danhBa[i].hoVaTen);
            printf("So dien thoai: %s\n", danhBa[i].phoneNumber);
            printf("Email: %s\n", danhBa[i].email);
            printf("Ban co chac chan muon xoa? (1: Co / 0: Khong): ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                for (int j = i; j < soLuongContacts - 1; j++) {
                    strcpy(danhBa[j].hoVaTen, danhBa[j + 1].hoVaTen);
                    strcpy(danhBa[j].phoneNumber, danhBa[j + 1].phoneNumber);
                    strcpy(danhBa[j].email, danhBa[j + 1].email);
                }
                soLuongContacts--;
                printf("Da xoa contact thanh cong.\n");
            } else {
                printf("Khong xoa contact.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay contact nao phu hop.\n");
    }
}

int compare(const void *a, const void *b) {
    return strcmp(((Contact *)a)->hoVaTen, ((Contact *)b)->hoVaTen);
}

void sapXepContact() {
    qsort(danhBa, soLuongContacts, sizeof(Contact), compare);
    printf("Danh ba da duoc sap xep theo ten.\n");
}
void showContact(){
    printf("|STT|  |Ho va Ten|      |SDT|        |Email|\n");
    printf("==============================================\n");
    for (int i = 0; i < soLuongContacts; i++) {
        printf("[%2d] %20s %10s %20s\n",i, danhBa[i].hoVaTen,danhBa[i].phoneNumber,danhBa[i].email);
    }
}
void addData() {
    danhBa[soLuongContacts++] = (Contact){"Nguyen Cong Quang", "0796659071", "wtvvnjk@gmail.com"};
    danhBa[soLuongContacts++] = (Contact){"Tran Thi Lan", "0987654321", "lantran@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Le Van An", "0123456789", "anlevan@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Hoang Thi Mai", "0912345678", "hoang@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Pham Van Cuong", "0981234567", "cuong@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Tran Minh Hieu", "0976543210", "hieutran@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Nguyen Thi Hien", "0909876543", "tnguyen@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Le Quang Huy", "0932109876", "huyle@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Vu Thi Thu", "0965432109", "thuvu@example.com"};
    danhBa[soLuongContacts++] = (Contact){"Do Van Phuc", "0943210987", "phucdo@example.com"};
}
void hienThiMenu() {
    printf("\nDanh ba dien thoai\n");
    printf("1. Them contact\n");
    printf("2. Tim kiem contact\n");
    printf("3. Xoa contact\n");
    printf("4. Sap xep danh ba theo ten\n");
    printf("5. Hien Thi Danh Ba\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}

int main() {
    int luaChon; addData();
    do {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themContact();
                break;
            case 2:
                timKiemContact();
                break;
            case 3:
                xoaContact();
                break;
            case 4:
                sapXepContact();
                break;
            case 5:
                showContact();
                break;
            case 6:
                printf("Cam on ban da su dung!\n"); 
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 6);

    return 0;
}
