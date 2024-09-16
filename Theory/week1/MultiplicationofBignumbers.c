#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


void multiplyLargeNumbers(char *num1, char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 1 && num1[0] == '0' || len2 == 1 && num2[0] == '0') {
        strcpy(result, "0");
        return;
    }
    int *tempResult = (int *)calloc(len1 + len2, sizeof(long long));

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int mul = digit1 * digit2;
            int pos1 = i + j;
            int pos2 = i + j + 1;
            int sum = mul + tempResult[pos2];

            tempResult[pos2] = sum % 10;   
            tempResult[pos1] += sum / 10;   
        }
    }
    int index = 0;
    int start = 0;
    while (start < len1 + len2 && tempResult[start] == 0) start++; // Bỏ qua các số 0 đầu
    for (int i = start; i < len1 + len2; i++) {
        result[index++] = tempResult[i] + '0';
    }
    result[index] = '\0';

    free(tempResult);
}

int main() {
    char num1[10001], num2[10001], result[20003]; 
    scanf("%s", num1);
    scanf("%s", num2);

    multiplyLargeNumbers(num1, num2, result);

    printf("%s\n", result);

    return 0;
}
