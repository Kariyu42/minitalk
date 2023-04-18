
# Minitalk

## Server part:

### 1ère étape:

```c
#include "libft.h"
#include "server.h"
#include "ft_print.h"
#include <signal.h>

int	main(void)
{
	ft_printf("%d\n", getpid());
	return (0);
}
```
La fonction getpid(); permet de recupere le process ID d'un processus. Celle-ci renvoie un pid_t qui un signed integer. On peut donc utilisé %d dans notre ft_printf(); pour enfin afficher le PID du processus server comme demandé dans le sujet de **Minitalk**.

# Key signals:

## Ctrl-C
Pressing this key causes the system to send an INT signal **(SIGINT)** to the running process. By default, this signal causes the process to immediately terminate.

## Ctrl-Z
Pressing this key causes the system to send a TSTP signal (SIGTSTP) to the running process. By default, this signal causes the process to suspend execution.

## Ctrl-\
Pressing this key causes the system to send a ABRT signal (SIGABRT) to the running process. By default, this signal causes the process to immediately terminate.

| Operations | Description |
| ------ | ----------- |
| SIGHUP | Hang-up the process. The SIGHUP signal is used to report disconnection of the user’s terminal, possibly because a remote connection is lost or hangs up. |
| SIGINT | Interrupt the process. When the user types the INTR character (normally Ctrl + C) the SIGINT signal is sent. |
| SIGQUIT | Quit the process. When the user types the QUIT character (normally Ctrl + \ ) the SIGQUIT signal is sent. |
| SIGILL | Illegal instruction. When an attempt is made to execute garbage or privileged instruction, the SIGILL signal is generated. Also, SIGILL can be generated when the stack overflows, or when the system has trouble running a signal handler. |
| SIGUSR1 & SIGUSR2 | The signals SIGUSR1 and SIGUSR2 may be used as you wish. It is useful to write a signal handler for them in the program that receives the signal for simple inter-process communication. |

## Default Action Of Signals
Each signal has a default action, one of the following:

__Term__: The process will terminate.<br>
__Core__: The process will terminate and produce a core dump file.<br>
__Ign__: The process will ignore the signal.<br>
__Stop__: The process will stop.<br>
__Cont__: The process will continue from being stopped.<br>


