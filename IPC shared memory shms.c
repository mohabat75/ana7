#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ 27
main()
{
 char c;
 int shmid;
 key_t key;
 char *shm, *s;
 /*
 * We'll name our shared memory segment
 * "5678".
 */
 key = 5678;
 /*
 * Create the segment.
 */
 if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
 perror("shmget");
 exit(1);
 }
 /*
 * Now we attach the segment to our data space.
 */
 if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
 perror("shmat");
 exit(1);
 }
 /*
 * Now put some things into the memory for the
 * other process to read.
 */
 s = shm;
 for (c = 'a'; c <= 'z'; c++)
 *s++ = c;
 *s = NULL;
 /*
 * Finally, we wait until the other process
 * changes the first character of our memory
 * to '*', indicating that it has read what
 * we put there.
 */
 while (*shm != '*')
 sleep(1);
 exit(0);
}



/*Outputavcoe@avcoe-HP-ProDesk-400-G1-SFF:~/Pr-7B$ gcc shm_server.c
shm_server.c:9:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 9 | main()
 | ^~~~
shm_server.c: In function ‘main’:
shm_server.c:46:8: warning: assignment to ‘char’ from ‘void *’ makes integer from pointer without
a cast [-Wint-conversion]
 46 | *s = NULL;
 | ^
shm_server.c:55:9: warning: implicit declaration of function ‘sleep’ [-Wimplicit-functiondeclaration]
 55 | sleep(1);
 | ^~~~~
avcoe@avcoe-HP-ProDesk-400-G1-SFF:~/Pr-7B$ ./a.out
*/
