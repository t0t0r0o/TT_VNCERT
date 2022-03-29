#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


// khai bao cau truc du lieu danh sach lien ket
struct node {
	int data;
	struct node *next;
    struct node *prev;
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
	p->prev = NULL; // khoi tao pPre voi node sau
	return p;
}



// them node vao dau danh sach 
void themDau(LIST &l, NODE *p) {
	if ( l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
        l.pHead->prev = p;
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
        p->prev = l.pTail;
		l.pTail = p; // p chinh thuc o cuoi danh sach
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


void xoaLe(LIST &l,int key) {
    for (NODE *p = l.pHead;p != NULL; p = p->next) {
		if (p->data == key) {
			if(p ->prev == NULL) {
				l.pHead = p->next;
			} else {
				p->prev->next = p->next;
			}

			if(p->next == NULL) {
				l.pTail = p->prev;
			} else {
				p->next->prev = p->prev;
			}
		}
	}
}


int main() {
	LIST l;
	nhapLieu(l);
	xuatLieu(l);
	xoaLe(l,3);
	printf("\n--------sau khi xoa la----------\n");
    xuatLieu(l);
	getchar();
}
