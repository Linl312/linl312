#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem {
    char name[50];
    int quantity;
    struct ShoppingItem* next; //指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL;

//1. 添加商品到购物清单：
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

//2. 从购物清单中移除商品：
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

//3. 查看购物清单：
void displayList() {
    struct ShoppingItem* current = shoppingList;
    printf("购物清单:\n");
    while (current != NULL) {
        printf("%s - 数量：%d\n", current->name, current->quantity);
        current = current->next;
    }
}

//4. 修改购物清单中商品的数量：
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

//5. 清空购物清单：
void clearList() {
    struct ShoppingItem* current = shoppingList;
    while (current != NULL) {
        struct ShoppingItem* temp = current;
        current = current->next;
        free(temp);
    }
    shoppingList = NULL;
}

//6. 计算购物清单中商品的总数量：
int totalQuantity() {
    struct ShoppingItem* current = shoppingList;
    int total = 0;
    while (current != NULL) {
        total += current->quantity;
        current = current->next;
    }
    return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
    struct ShoppingItem* current = shoppingList;
    printf("查找商品 \"%s\" ：\n", itemName);
    while (current != NULL) {
        if (strcmp(current->name, itemName) == 0) {
            printf("%s - 数量：%d\n", current->name, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("未找到商品 \"%s\"。\n", itemName);
}

//8. 排序购物清单：
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

//9. 合并购物清单：
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

//10. 删除购物清单中的商品：
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
    printf("输入1：添加商品到购物清单\n");
    printf("输入2. 从购物清单中移除商品\n");
    printf("输入3. 查看购物清单\n");
    printf("输入4. 修改购物清单中商品的数量\n");
    printf("输入5. 清空购物清单\n");
    printf("输入6. 计算购物清单中商品的总数量\n");
    printf("输入7. 查找购物清单中的商品\n");
    printf("输入8. 排序购物清单\n");
    printf("输入9. 合并购物清单\n");
    printf("输入10. 删除购物清单中的商品\n");
    printf("输入0.结束程序\n");
    printf("=================================\n");
    int n;
    char itemName[50];
    int itemQuantity, newItemQuantity, deleteAll;
    scanf("%d",&n);
    while(n != 0) {
        switch (n) {
            case 1:
            {
			    printf("请输入要添加的商品名和数量（空格分隔）：");
                scanf("%s %d", itemName, &itemQuantity);
                addItem(itemName, itemQuantity);
                break;
        	}
			case 2:
            {
			    printf("请输入要移除的商品名：");
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
			    printf("请输入要修改数量的商品名和新的数量（空格分隔）：");
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
                printf("购物清单中商品的总数量：%d\n", totalQuantity());
                break;
        	}
			case 7:
            {
				printf("请输入要查找的商品名：");
                scanf("%s", itemName);
                findItem(itemName);
                break;
        	}
			case 8:
            {
			    sortList();
                printf("购物清单排序完成。\n");
                break;
            }
            case 9:
            	{
                printf("合并购物清单，请输入第二个购物清单的商品名和数量（空格分隔）：");
                scanf("%s %d", itemName, &itemQuantity);
                struct ShoppingItem* list2 = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
                strcpy(list2->name, itemName);
                list2->quantity = itemQuantity;
                list2->next = NULL;
                mergeLists(&shoppingList, &list2);
                printf("购物清单合并完成。\n");
                break;
            }
            case 10:
			{
                printf("请输入要删除的商品名：");
                scanf("%s", itemName);
                printf("是否删除所有匹配项？（1-是，0-否）：");
                scanf("%d", &deleteAll);
                deleteItem(itemName, deleteAll);
                break;
			}
        }
        
        printf("=================================\n");
        printf("输入1：添加商品到购物清单\n");
        printf("输入2. 从购物清单中移除商品\n");
        printf("输入3. 查看购物清单\n");
        printf("输入4. 修改购物清单中商品的数量\n");
        printf("输入5. 清空购物清单\n");
        printf("输入6. 计算购物清单中商品的总数量\n");
        printf("输入7. 查找购物清单中的商品\n");
        printf("输入8. 排序购物清单\n");
        printf("输入9. 合并购物清单\n");
        printf("输入10. 删除购物清单中的商品\n");
        printf("输入0. 结束程序\n");
        printf("=================================\n");
        
        fflush(stdin);  // 清空缓冲区，避免读入错误
        
        scanf("%d",&n);
    }
    
    return 0;
}
