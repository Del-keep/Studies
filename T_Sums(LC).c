#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    int *result;
    *returnSize = 2;

    result = malloc(2 * sizeof(int));
    if (!result) return NULL;

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL; 
}

int main() {
    int *n,t,c,i,returnSize,*indices;

    printf("Quantos numeros? ");
    scanf("%d", &c);

    n = malloc(c*sizeof(int));
    if (!n) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < c; i++) {
        printf("n[%d]: ", i);
        scanf("%d", &n[i]);
    }

    printf("Target: ");
    scanf("%d", &t);

    indices = twoSum(n, c, t, &returnSize);

    if (indices) {
        printf("Indices encontrados: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("Sem combinacao.\n");
    }

    free(n); 

    return 0;
}
