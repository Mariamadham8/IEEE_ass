//q2)
/*
#include <stdio.h>

int main() {
    int num;

    printf("input number: ");
    scanf("%d", &num);
    int msb = 1 << (sizeof(int) * 8 - 1); // Left shift 1 to the most significant bit position
    if (num & msb) {
        printf("most significant bit (MSB) of %d is set (1).\n", num);
    } else {
        printf("most significant bit (MSB) of %d is not set (0).\n", num);
    }

    
}
*/

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//q3)

/*
#include <stdio.h>

int main() {
    int num, n;
    
    
    printf("input number: ");
    scanf("%d", &num);
    printf("input nth bit number: ");
    scanf("%d", &n);

    
    int bit = (num >> n) & 1; 
    if (bit) {
        printf("%d bit of %d is set (1).\n", n, num);
    } else {
        printf("%d bit of %d is not set (0).\n", n, num);
    }

    
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//q4)

/*
#include <stdio.h>

int main() {
    int num, n, new_num;
    
    printf("input number: ");
    scanf("%d", &num);
    printf("input nth bit to set: ");
    scanf("%d", &n);
    new_num = num | (1 << n);
    printf("number after setting nth bit: %d in decimal\n", new_num);

}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//q5)

/*
#include <stdio.h>

int main() {
    int num, n, new_num;
    printf("nput number: ");
    scanf("%d", &num);
    printf("input nth bit to clear: ");
    scanf("%d", &n);
    new_num = num & ~(1 << n); 
    printf("number after clearing nth bit: %d (in decimal)\n", new_num);

 
}

*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//q6)

/*
#include <stdio.h>

int main() {
    int num, n, new_num;

    printf("input number: ");
    scanf("%d", &num);
    printf("input nth bit to toggle: ");
    scanf("%d", &n);
    new_num = num ^ (1 << n); 
    printf("after toggling nth bit: %d (in decimal)\n", new_num);

 }

*/
//$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//q12)
/*
#include <stdio.h>

int main() {
    int num, ones = 0, zeros = 0;
    printf("input any number: ");
    scanf("%d", &num);
    int bits = sizeof(int) * 8;
    for (int i = 0; i < bits; i++) {
        if (num & (1 << i)) {
            ones++;
        } else {
            zeros++;
        }
    }
    printf("output number of ones: %d\n", ones);
    printf("output number of zeros: %d\n", zeros);

}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//q14)
/*
#include <stdio.h>

void decimalToBinary(int num) {
    int bits = sizeof(int) * 8;
    int binary[bits];

    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = num & 1; 
        num >>= 1; 
    }
    printf("Binary number: ");
    for (int i = 0; i < bits; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Input any number: ");
    scanf("%d", &num);
    decimalToBinary(num);
    return 0;
}
*/



