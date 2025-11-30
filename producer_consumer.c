#include <stdio.h>
#define BUF_SIZE 10 // Define buffer size
int main() {
 int buffer[BUF_SIZE], in = 0, out = 0, produce, consume, choice = 0;
 while (choice != 3) {
 printf("\n1. Produce\t2. Consume\t3. Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 if ((in + 1) % BUF_SIZE == out) {
 printf("\nBuffer is Full");
 } else {
 printf("\nEnter the value: ");
 scanf("%d", &produce);
 buffer[in] = produce;
 in = (in + 1) % BUF_SIZE;
 }
 break;
 case 2:
 if (in == out) {
 printf("\nBuffer is Empty");
 } else {
 consume = buffer[out];
 printf("\nThe consumed value is %d", consume);
 out = (out + 1) % BUF_SIZE;
 }
 break;
 case 3:
 printf("\nExiting the program...\n");
 break;
 default:
 printf("\nInvalid choice! Please enter 1, 2, or 3.");
 }
 }
 return 0;
}
