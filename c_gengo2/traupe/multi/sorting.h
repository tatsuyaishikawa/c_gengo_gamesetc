#define PROCS 2/*al; core) */
#define CHILD 1/* 子プロセス１ */
#define PARENT 0/* 親プロセス */
#define ON 1
#define OFF 0
#define N 100000/* 10万個 */

struct set1 {/* common variable */
int dat[N], temp[N];/* data buffer */
signed char flag[PROCS];/* condition flag */
pid_t id_number[PROCS];/* id code */
} *ptr;

