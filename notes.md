
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

# Les processus.
> 💻 Un programme existe sur disque dur ; un processus en mémoire vive.
## ___La hiérarchie des processus___
## Les commandes:

Afin de voir les processus actifs sur un systeme Unix, on peut utiliser la commande:
```shell
$ps -e
```

Et pour voir un processus specifié, on peut utiliser la commande __pidof__:
```shell
$pidof systemd
$pidof top
$pidof pidof
```
## Les processus ne possèdent pas qu'un seul PID (Process IDentifier):
Ils ont aussi une référence à leur processus père: le __PPID__ (Parent Process IDentifier).

On peut avoir le PID et le PPID du shell de notre terminal avec la commande suivante:
```shell
$echo "PID = $$; PPID = $PPID"
```
__Les processus sont organisés de manière hiérarchique avec:__

- des __processus père__, qui engendre des processus fils,
- des __processus fils__, crées par leur processus père et qui peuvent à leur tour engendrer d'autres fils.

***Exemple:***

> Quand on indique au shell de lancer une commande telle que "ls", le shell crée un processus fils qui a pour tâche d’exécuter le programme ls. Si le shell exécutait directement le programme ls sans créer de fils au préalable, le processus du shell serait entièrement remplacé par le programme ls et on ne pourrait plus rien faire dans notre shell…

Au démarrage d’un système de type Unix, il n’y a qu’un seul processus, appelé "init", qui possède le PID 1. Celui-ci est l’ascendant direct ou indirect de tous les autres processus lancés sur le système.

# Fork : donner naissance à un processus fils

La fonction fork va permettre a notre processus de donner naissance a un nouveau processus qui sera sa copie conforme et qui sera executé en parallèle. Notre processus de base va donc etre le père du nouveau processus fils. Le nom Fork() fait ref a la fourche d'un arbre genealogique.

fork(); utilise la bibliotheque <unistd.h>.:
```c
pid_t fork(void)
```

L'important est de savoir la valeur de retour... la fonction nous informera si la creation du processus fils s'est bien passée, mais ce n'est pas tout...

# Distinguer le processus père du processus fils

Afin de les distinguer, car ce sont des clones l'un de l'autre, les valeurs de retour possible de la fonction fork sont:

- le père recoit en retour le PID du fils.
- le fils recoit 0,
- et en cas d'erreur il renvoit -1.

Donc si le nombre est sup a 0 alors, on sait qu'on est dans le processus père.

# Mémoire dupliquée mais pas partagée
Sur le moment oú l'on a compris que le processus fils est une copie identique de son processus père, si on change la valeur d'une variable apres avoir creer son processus fils, alors le fils ne verra pas le changement s'il consulte cette meme variable.

# Wait : attendre les processus fils
```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
        sleep(1); // Attendre 1 seconde.
        printf("Fils : Termine !\n");
    }
    else if (pid > 0)
    {
        printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
        printf("Pere : Termine !\n");
    }
    return (0);
}
```
Le résultat est pour le peu étrange :
![Alt text](https://www.codequoi.com/wp-content/uploads/2022/10/process_fork_no_wait_example.png)

> On nous rend l’invite de commandes avant même que le processus fils ait terminé. C’est parce que le shell attend uniquement que notre processus père (son fils) se termine. Il ne se soucie pas du processus fils de notre programme (le petit-fils du shell). Dans un cas comme celui-ci, quand le père se termine sans attendre son fils, le fils devient un processus orphelin. Il est alors adopté par init (son PPID devient 1) et promptement éliminé du système.

# Attendre pour éviter les zombies

__Un processus zombie__: c’est un processus qui a terminé sa tâche mais qui reste présent en attendant que son père le prenne en compte.

# Convertir un char en Binaire


