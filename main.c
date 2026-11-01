#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number;
    int guess;
    int attempts = 0;
    int max_attempts = 7; // 限制最多猜 7 次

    // 初始化随机数种子
    srand(time(0)); 
    // 生成 1 到 100 之间的随机数
    secret_number = rand() % 100 + 1; 

    printf("=================================\n");
    printf("    欢迎来到猜数字小游戏！\n");
    printf("=================================\n");
    printf("我已经想好了一个 1 到 100 之间的数字。\n");
    printf("你有 %d 次机会来猜它。\n\n", max_attempts);

    while (attempts < max_attempts) {
        printf("请输入你猜的数字 (还剩 %d 次机会): ", max_attempts - attempts);
        
        // 读取用户输入
        if (scanf("%d", &guess) != 1) {
            printf("输入无效，请输入一个数字！\n");
            // 清理输入缓冲区
            while(getchar() != '\n'); 
            continue;
        }

        attempts++;

        if (guess > secret_number) {
            printf("太大了！再往下猜猜。\n\n");
        } else if (guess < secret_number) {
            printf("太小了！再往上猜猜。\n\n");
        } else {
            printf("\n 恭喜你，猜对了！\n");
            printf("你一共用了 %d 次机会。\n", attempts);
            return 0; // 游戏胜利，结束程序
        }
    }

    // 机会用完还没猜对
    printf("\n😢 很遗憾，你的机会用完了。\n");
    printf("正确的数字是：%d\n", secret_number);
    printf("再试一次吧！\n");

    return 0;
}
