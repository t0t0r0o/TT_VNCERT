#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


// khai bao cau truc du lieu danh sach lien ket
struct node {
	int data;
	struct node *next;
};

typedef struct node NODE;


struct List {
	NODE *pHead;
	NODE *pTail;
};

typedef struct List LIST;

//khoi tao danh sach
void khoitaolist(LIST &l) {
	l.pHead = l.pTail =NULL;
}



// tao node trong danh sach
NODE* getNode(int x) {
	NODE *p= (NODE*)malloc(sizeof(NODE));
	if (p==NULL) {
		return NULL;
	}
	p->data = x; // luu x vao data
	p->next = NULL; // khoi tao pNext voi node sau
	return p;
}



// them node vao dau danh sach 
void themDau(LIST &l, NODE *p) {
	if ( l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		p->next = l.pHead; // p quang day noi voi pHead
		l.pHead = p; // p chinh thuc o dau danh sach
	}
}



// them node vao cuoi danh sach 
void themCuoi(LIST &l, NODE *p) {
	if ( l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		l.pTail->next = p; // pTail quang day noi voi p
		l.pTail = p; // p chinh thuc o cuoi danh sach
        p->next = NULL;
	}
}



// nhap du lieu cho danh sach
void nhapLieu(LIST &l) {
	char c;
	khoitaolist(l);
	do {
		int x;
		fflush(stdin);
		printf("\nnhap vao data: ");scanf("%4d",&x);
		NODE *p = getNode(x);
		themCuoi(l,p);
		fflush(stdin);
		printf("\nco muon tiep tuc khong: "); c=getchar();
	} while (c!='d');
}


//xuat du lieu
void xuatLieu(LIST l) {
	for (NODE *p = l.pHead;p; p = p->next) {
		printf("%4d",p->data);
	}
}


List xoaTrung(LIST &l) {
    List l1;
    khoitaolist(l1);
    NODE *check = l.pHead;
    NODE *p = check->next;
    while(p != NULL) {
		if (p->data != check->data) {
			themCuoi(l1,check);
		}
        if(p->next == NULL) {
            break;
        }
        check = p;
        p = p->next;
	}
    themCuoi(l1,p);
    return l1;
}


int main() {
	LIST l;
	nhapLieu(l);
    printf("\n--------day ban dau la----------\n");
	xuatLieu(l);
	printf("\n--------sau khi xoa la----------\n");
    xuatLieu(xoaTrung(l));
	getchar();
}
