#include <stdio.h>
#define LEN 10

int binsearchrec(int x, int len, int a[]) {
   return binsearchrec0(x, len, a, 0, LEN - 1);
}

int binsearchrec0(int x, int len, int a[], int low, int high) {
   int mid;
   if (low > high) return -1;
   mid = (low + high)/2;
   if (a[mid] == x) return mid;
   else if (a[mid] < x)
      return binsearchrec0(x, LEN, a, mid+1,high);
   else
      return binsearchrec0(x, LEN, a, low, mid-1);
}

int main() {

   int a[] = {2, 8,12,14,16,19,24,28,31,33};
   int i;
   for (i = 0; i < LEN; i++)
      printf("%i ", binsearchrec(a[i], LEN, a));
   printf("\n");
   printf("%i ", binsearchrec(1, LEN, a));
   printf("%i ", binsearchrec(2, LEN, a));
   printf("%i ", binsearchrec(33, LEN, a));
   printf("%i ", binsearchrec(99, LEN, a));
   printf("\n");
}