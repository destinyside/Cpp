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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(l1 == NULL){
		return l2;
	}
	if(l2 == NULL){
		return l1;
	}
	struct ListNode* head = NULL;
	struct ListNode* one = l1;
	struct ListNode* other = l2;
	if(one->val < other->val){
		head = one;
		one = one->next;
	} else {
		head = other;
		other = other->next;
	}
	head->next = NULL;
	struct ListNode* p = head;
	while(one != NULL || other != NULL){
		printList(one);
		printList(other);
		while(p->next != NULL){
			p = p->next;
		}
		if(one != NULL && other != NULL){
			if(one->val < other->val){
				p->next = one;
				one = one->next;
			} else {
				p->next = other;
				other = other->next;
			}
			p->next->next = NULL;
		} else if(one != NULL){
			p->next = one;
			break;
		} else if(other != NULL){
			p->next = other;
			break;
		} else {
			return head;
		}
	}
	return head;
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
	int* arr1;
	int* arr2;
	if(argc > 1){
		len = argc - 1;
		arr1 = malloc(sizeof(int)*len);
		arr2 = malloc(sizeof(int)*len);
		for(int i=0; i<len; i++){
			arr1[i] = atoi(argv[i+1]);
			arr2[i] = atoi(argv[i+1]);
		}
	} else {
		len = 20;
		arr1 = randomArray(len);
		arr2 = randomArray(len);
		/*
		   printf("%d\n",len);
		   for(int i=0; i<len; i++){
		   printf("%d ",arr[i]);
		   }
		   printf("\n");
		   */
	}
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	l1 = makeList(arr1,len);
	l2 = makeList(arr2,len);
	printList(l1);
	printList(l2);
	struct ListNode* lm = mergeTwoLists(l1,l2);
	printList(lm);
	freeList(lm);
	return EXIT_SUCCESS;
}
