#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

void printList(struct ListNode* head){
	struct ListNode* temp = head;
	while(temp != NULL){
		printf("%d ",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void reorderList(struct ListNode* head){
	struct ListNode* left = head;
	struct ListNode* right = head;
	while(left->next != NULL){
		right = left;
		while(right->next->next!=NULL){
			right = right->next;
		}
		struct ListNode* tail = right->next;
		right->next = NULL;
		tail->next = left->next;
		left->next = tail;
		left = tail->next;
		printList(head);
		if(left == NULL){
			break;
		}
	}
}

struct ListNode* makeList(int* arr, int len){
	struct ListNode* head = NULL;
	for(int i=0; i<len; i++){
		if(head==NULL){
			head = malloc(sizeof(struct ListNode));
			head->val = arr[i];
			head->next = NULL;
		} else {
			struct ListNode* p = head;
			while(p->next != NULL){
				p = p->next;
			}
			p->next = malloc(sizeof(struct ListNode));
			p->next->val = arr[i];
			p->next->next = NULL;
		}
	}
	return head;

}


void freeList(struct ListNode* head) {
	//一个一个NULL
	struct ListNode* temp =head;		//定义一个临时变量来指向头
	while (temp !=NULL)
	{
		//	printf("%d\n",temp->a);
		struct ListNode* pt =temp;
		temp = temp->next;		//temp指向下一个的地址 即实现++操作
		free(pt);					//释放当前
	}
	//头尾清空	不然下次的头就接着0x10
	head = NULL;
}

int* randomArray(int len) {

	srand((unsigned)time(0));
	int* tmp = malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len + 1;
	}
	return tmp;
}

int main(int argc,char* argv[]){
	int len=0;
	int* arr;
	if(argc > 1){
		len = argc - 1;
		arr = malloc(sizeof(int)*len);
		for(int i=0; i<len; i++){
			arr[i] = atoi(argv[i+1]);
		}
	} else {
		len = 20;
		arr = randomArray(len);
		/*
		printf("%d\n",len);
		for(int i=0; i<len; i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		*/
	}
	struct ListNode* head = NULL;
	head = makeList(arr,len);
	printList(head);
	reorderList(head);
	printList(head);
	freeList(head);
	return EXIT_SUCCESS;
}
