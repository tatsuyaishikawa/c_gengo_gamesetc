#include <stdio.h>/* for printf() */
#include <unistd.h>/* for getpid() */
#include <stdlib.h>/* for exit() */
#include <string.h>
#include <time.h>
#include <sys/types.h>/* for shared memory */
#include <sys/ipc.h>/* 〃 */
#include <sys/shm.h>/* 〃 */
#include <sys/stat.h>
#include <signal.h>/* for signal */
#include <errno.h>
#include "sorting.h"/* 共通 struct構造体 */

#define CODE 999/* 適当に変更のこと */

void shell_sort(int *, int);
void pri_out(char *, int *, char *);
double second(void);
void handler(int);

int main(void) {
int shmid;/* 共有メモリ関連 */
void *shmaddr;/* 〃 */
char command_line[64];
int i;
double start;


/* 共有メモリの確保 */
if (((shmid = shmget(CODE, sizeof(*ptr) + 2, IPC_CREAT | S_IRUSR | S_IWUSR)) == -1)
|| ((shmaddr = shmat(shmid, NULL, 0)) == (char *)-1)) {
perror("Shared memory set");
exit(1);
}

/* 共有メモリに struct構造体をあてがう */
ptr = (struct set1 *)shmaddr;

/* 自身プロセスIdを記録する */
ptr->id_number[PARENT] = getpid();

/* シグナルハンドラー登録 */
signal(SIGCONT, handler);

/* 共有メモリに乱数を用意 */
srand(time(NULL));
for(i=0;i<N;i++)
ptr->temp[i] = ptr->dat[i] = (int)rand() % N + 1;

/* 乱数データの出力 */
pri_out("Random data:", ptr->temp, "\n\n");

/* バックグランドで同時計算可に*/
ptr->flag[PARENT] = ON;// 子プロセス完了まで待つ
sprintf(command_line, "./sort_sub %d &", shmid);
if (system(command_line) != 0) {
perror("Shell command line　error");
exit(1);
}
/* 子プロセスの順延に配慮 */
fprintf(stderr, "Program setting now");
while (ptr->flag[PARENT] != OFF) {
fprintf(stderr, ".");
sleep(1);
}

/* 子プロセスへ並列計算するようシグナルを送信 */
ptr->flag[PARENT] = ON;// 計算状態に有り
ptr->flag[CHILD] = OFF;// 並列計算せよ
kill(ptr->id_number[CHILD], SIGCONT);

/* 乱数データをソーティング */
start=second();
shell_sort(ptr->temp, N);

/* 結果の出力 */
fprintf(stderr, "\n");
printf("The executed time of %d data by Shell sort is %.5f sec.\n", N, second() - start);
pri_out("\n\nSorted data:", ptr->temp, "");

/* 計算終了まで待機（dead_lockの回避）
*作業継続入力後も子プロセスが処理中なら１秒休む。
*ただし、処理が完了したならシグナル等で起こされる。
*/
while (ptr->flag[PARENT] != OFF) {// 子プロセスが操作
fprintf(stderr, "."), fflush(stderr);
sleep(1);
}
fprintf(stderr, "\n");

/* 子プロセスのプログラム終了送信 */
ptr->flag[CHILD] = ON;// 計算終了せよ
kill(ptr->id_number[CHILD], SIGCONT);

/* 共有メモリの解除 */
if (shmdt(shmaddr) == -1 ||
shmctl(shmid, IPC_RMID, 0) == -1) {
perror("Shared memory closed");
exit(1);
}

return 0;
}

/* シェルソート */
void shell_sort(int d[], int n) {
int i, j;
int temp;
for (i = 1; i < n; i++) {
temp = d[i];
for (j = i - 1; j >= 0 && d[j] > temp; j--)
d[j + 1] = d[j];
d[j + 1] = temp;
}
}


void pri_out(char *comment, int a[], char *tail) {
int i;
fprintf(stderr, "%s\n", comment);
for (i = 0; i < 100; i++)
fprintf(stderr, "%d ", a[i]);
fprintf(stderr, " .... ");
for (i = N-100; i < N; i++)
fprintf(stderr, "%d ", a[i]);
fprintf(stderr, "%s\n", tail);
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
