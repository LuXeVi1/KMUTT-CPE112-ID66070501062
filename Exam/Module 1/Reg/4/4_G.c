#include <stdio.h>

// Create a structure for the node in the Priority Queue by collecting data and Priority Next, which points to the next Node for the Priority value.If the data is small, it is very priority and the data is very valuable.
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// For putting data into the Priority Queue, with the order according to the Priority
void enqueue(int data, int priority) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    
    // If Queue is empty or new node has high priority
    if (PQ == NULL || priority < PQ->priority) {
        newNode->next = PQ;
        PQ = newNode;
    } else {
        Node* temp = PQ;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


// For removing data from Priority Queue
void dequeue() {
    if (PQ == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    Node* temp = PQ;
    PQ = PQ->next;
    free(temp);
}


// For the first data returns, Priority Queue
void peek() {
    if (PQ == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Front element in Priority Queue: %d\n", PQ->data);
}


// For showing all the information in the Priority Queue
void display() {
    Node* temp = PQ;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int minSum(int N, int* arr) {
    // Implement the logic to find the min sum of numbers from the array
}


int main (){
    int main() {
    int N;
    scanf("%d", &N);
    
    if(N == 0) {
        printf("Invalid\n");
        return 0;
    }
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        enqueue(arr[i], arr[i]);
    }
    
    display();
    
    peek(); 
    
    dequeue();
    dequeue();
    
    display();
    
    int result = minSum(N, arr);
    printf("%d\n", result); 
    
    return 0;
}

}
