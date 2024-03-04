#include <stdio.h>

int jiecheng[11]; // 声明阶乘数组

// 计算阶乘
void factorial() {
    jiecheng[0] = 1;
    for (int i = 1; i < 11; i++) {
        jiecheng[i] = i * jiecheng[i - 1];
    }
}

// 打印全排列
void print(int output[], int N) {
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", output[i]);
    }
    printf("%d\n", output[N - 1]);
}

// 生成下一个全排列
void find(int output[], int N) {
    int i;
    for (i = N - 2; i >= 0; i--) {
        if (output[i] < output[i + 1]) {
            break;
        }
    }
    int k1 = i;
    int temp_low = i + 1;
    for (i = k1 + 1; i < N; i++) {
        if (output[i] > output[k1] && output[i] < output[temp_low]) {
            temp_low = i;
        }
    }
    int temp = output[k1];
    output[k1] = output[temp_low];
    output[temp_low] = temp;
    for (int j = k1 + 1, i = N - 1; i > j; i--, j++) {
        temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}

int main() {
    factorial();
    int N;
    scanf("%d", &N);
    int output[10];
    for (int i = 0; i < N; i++) {
        output[i] = i + 1;
    }
    print(output, N);
    for (int i = 1; i < jiecheng[N]; i++) {
        find(output, N);
        print(output, N);
    }
    return 0;
}
