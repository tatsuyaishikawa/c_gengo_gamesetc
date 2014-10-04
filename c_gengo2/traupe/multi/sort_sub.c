#include <stdio.h>/* for printf() */
#include <unistd.h>/* for getpid() */
#include <stdlib.h>/* for exit() */
#include <sys/types.h>/* for shared memory */
#include <sys/ipc.h>/* 〃 */
#include <sys/shm.h>/* 〃 */
#include <sys/stat.h>
#include <signal.h>/* for signal */
#include <errno.h>
#include "sorting.h"/* 共通 struct構造体 */

void bubble_sort(int *, int);
double second(void);
void handler(int);

int main(int argc, char *argv[]) {
int shmid;/* 共有メモリ関連 */
void *shmaddr;/* 〃 */
double start;

/* 親プロセスから受け継ぐ */
shmid = atoi(argv[--argc]);
if ((shmaddr = shmat(shmid, NULL, 0)) == (char *)-1) {
perror("Shared menory set");
exit(1);
}

/* 共有メモリに struct構造体をあてがう */
ptr = (struct set1 *)shmaddr;

/* 自身プロセスIdを記録する */
ptr->id_number[CHILD] = getpid();
//ptr->flag[CHILD] = OFF;

/* シグナルハンドラー登録 */
signal(SIGCONT, handler);

/* 親プロセスに「スタンバイ ok!」を知らせる */
ptr->flag[PARENT] = OFF;// スタンバイ ok
kill(ptr->id_number[PARENT], SIGCONT);

while (1) {
/* 親プロセスからのシグナルを待つ */
pause();

if (ptr->flag[CHILD] != OFF)// 計算終了
break;
else {// 計算開始
fprintf(stderr, " And sub program runninng now. ");
fflush(stderr);
start = second();
bubble_sort(ptr->dat, N);// バブルソート
fprintf(stderr, "\n");
printf("The executed time of %d data by Bubble sort is %.5f sec.\n", N, second() - start);
ptr->flag[PARENT] = OFF;// 計算状態が終了
kill(ptr->id_number[PARENT], SIGCONT);
}
}

if (shmdt(shmaddr) == -1) {
perror("Shared menory closed");
exit(1);
}

return 0;
}


/* バブルソート */
void bubble_sort(int d[], int n) {
int i, j, temp;
for (i = 0; i < n - 1; i++) {
for (j = n - 1; j > i; j--) {
if (d[j - 1] > d[j]) {
temp = d[j];
d[j] = d[j - 1];
d[j - 1]= temp;
}
}
}
}


/* 稼働時間測定 */
double second() {
struct timeval tv;
gettimeofday(&tv, NULL);
return tv.tv_sec + tv.tv_usec / 1.0e6;
}


/* 何もしないシグナル処理関数 */
void handler(int dummy){
;
}
