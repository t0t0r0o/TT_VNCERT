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


void xoaLe(LIST &l) {
    for (NODE *p = l.pHead;p != NULL; p = p->next) {
		if (p->data%2!=0) {
			if(p == l.pHead) {
				l.pHead = p->next;
				free(p);
			} else {
				printf("\nphan bi xoa la %d",p->data);
				NODE *tmp;
				for(tmp = l.pHead; tmp->next!=p;tmp = tmp->next);
				
				tmp->next = p->next;
				free(p);
			}
		}
	}
}


int main() {
	LIST l;
	nhapLieu(l);
	xuatLieu(l);
	xoaLe(l);
	printf("\n--------sau khi xoa la----------\n");
    xuatLieu(l);
	getchar();
}
