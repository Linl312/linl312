#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem {
    char name[50];
    int quantity;
    struct ShoppingItem* next; //ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL;

//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->next = NULL;

    if (shoppingList == NULL) {
        shoppingList = newItem;
    } else {
        struct ShoppingItem* current = shoppingList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

//2. �ӹ����嵥���Ƴ���Ʒ��
void removeItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                shoppingList = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

//3. �鿴�����嵥��
void displayList() {
    struct ShoppingItem* current = shoppingList;
    printf("�����嵥:\n");
    while (current != NULL) {
        printf("%s - ������%d\n", current->name, current->quantity);
        current = current->next;
    }
}

//4. �޸Ĺ����嵥����Ʒ��������
void updateQuantity(char itemName[], int newItemQuantity) {
    struct ShoppingItem* current = shoppingList;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            current->quantity = newItemQuantity;
            break;
        }
        current = current->next;
    }
}

//5. ��չ����嵥��
void clearList() {
    struct ShoppingItem* current = shoppingList;
    while (current != NULL) {
        struct ShoppingItem* temp = current;
        current = current->next;
        free(temp);
    }
    shoppingList = NULL;
}

//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
    struct ShoppingItem* current = shoppingList;
    int total = 0;
    while (current != NULL) {
        total += current->quantity;
        current = current->next;
    }
    return total;
}

//7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    printf("������Ʒ \"%s\" ��\n", itemName);
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            printf("%s - ������%d\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}

//8. �������嵥��
void sortList() {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* nextItem = NULL;
    char tempName[50];
    int tempQuantity;
    while (current != NULL) {
        nextItem = current->next;
        while (nextItem != NULL) {
            if (strcmp(current->name, nextItem->name) > 0) {
                strcpy(tempName, current->name);
                tempQuantity = current->quantity;

                strcpy(current->name, nextItem->name);
                current->quantity = nextItem->quantity;

                strcpy(nextItem->name, tempName);
                nextItem->quantity = tempQuantity;
            }
            nextItem = nextItem->next;
        }
        current = current->next;
    }
}

//9. �ϲ������嵥��
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else {
        struct ShoppingItem* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *list2;
    }
    *list2 = NULL;
}

//10. ɾ�������嵥�е���Ʒ��
void deleteItem(char itemName[], int deleteAll) {
    struct ShoppingItem* current = shoppingList;
    struct ShoppingItem* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            if (prev == NULL) {
                struct ShoppingItem* temp = shoppingList;
                shoppingList = shoppingList->next;
                free(temp);
                if (!deleteAll) break;
            } else {
                struct ShoppingItem* temp = current;
                prev->next = current->next;
                current = current->next;
                free(temp);
                if (!deleteAll) break;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    printf("=================================\n");
    printf("����1�������Ʒ�������嵥\n");
    printf("����2. �ӹ����嵥���Ƴ���Ʒ\n");
    printf("����3. �鿴�����嵥\n");
    printf("����4. �޸Ĺ����嵥����Ʒ������\n");
    printf("����5. ��չ����嵥\n");
    printf("����6. ���㹺���嵥����Ʒ��������\n");
    printf("����7. ���ҹ����嵥�е���Ʒ\n");
    printf("����8. �������嵥\n");
    printf("����9. �ϲ������嵥\n");
    printf("����10. ɾ�������嵥�е���Ʒ\n");
    printf("����0.��������\n");
    printf("=================================\n");
    int n;
    char itemName[50];
    int itemQuantity, newItemQuantity, deleteAll;
    scanf("%d",&n);
    while(n != 0) {
        switch (n) {
            case 1:
            {
			    printf("������Ҫ��ӵ���Ʒ�����������ո�ָ�����");
                scanf("%s %d", itemName, &itemQuantity);
                addItem(itemName, itemQuantity);
                break;
        	}
			case 2:
            {
			    printf("������Ҫ�Ƴ�����Ʒ����");
                scanf("%s", itemName);
                removeItem(itemName);
                break;
        	}
			case 3:
            {
			    displayList();
            
			}    break;
            case 4:
            {
			    printf("������Ҫ�޸���������Ʒ�����µ��������ո�ָ�����");
                scanf("%s %d", itemName, &newItemQuantity);
                updateQuantity(itemName, newItemQuantity);
                break;
        	}
			case 5:
            {
			    clearList();
                break;
        	}
			case 6:
            {
                printf("�����嵥����Ʒ����������%d\n", totalQuantity());
                break;
        	}
			case 7:
            {
				printf("������Ҫ���ҵ���Ʒ����");
                scanf("%s", itemName);
                findItem(itemName);
                break;
        	}
			case 8:
            {
			    sortList();
                printf("�����嵥������ɡ�\n");
                break;
            }
            case 9:
            	{
                printf("�ϲ������嵥��������ڶ��������嵥����Ʒ�����������ո�ָ�����");
                scanf("%s %d", itemName, &itemQuantity);
                struct ShoppingItem* list2 = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
                strcpy(list2->name, itemName);
                list2->quantity = itemQuantity;
                list2->next = NULL;
                mergeLists(&shoppingList, &list2);
                printf("�����嵥�ϲ���ɡ�\n");
                break;
            }
            case 10:
			{
                printf("������Ҫɾ������Ʒ����");
                scanf("%s", itemName);
                printf("�Ƿ�ɾ������ƥ�����1-�ǣ�0-�񣩣�");
                scanf("%d", &deleteAll);
                deleteItem(itemName, deleteAll);
                break;
			}
        }
        
        printf("=================================\n");
        printf("����1�������Ʒ�������嵥\n");
        printf("����2. �ӹ����嵥���Ƴ���Ʒ\n");
        printf("����3. �鿴�����嵥\n");
        printf("����4. �޸Ĺ����嵥����Ʒ������\n");
        printf("����5. ��չ����嵥\n");
        printf("����6. ���㹺���嵥����Ʒ��������\n");
        printf("����7. ���ҹ����嵥�е���Ʒ\n");
        printf("����8. �������嵥\n");
        printf("����9. �ϲ������嵥\n");
        printf("����10. ɾ�������嵥�е���Ʒ\n");
        printf("����0. ��������\n");
        printf("=================================\n");
        
        fflush(stdin);  // ��ջ�����������������
        
        scanf("%d",&n);
    }
    
    return 0;
}
