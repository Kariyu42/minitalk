# Send & intercept a signal in C

Pour chaque processus, le système maintient 2 vecteurs de bits :
- **pending** pour surveiller les signaux en attente,
- **blocked** pour suivre les signaux bloqués.

Lorsqu’il envoie un signal, le système ne fait que mettre le bit associé au signal à 1 dans le vecteur pending du processus destinataire.
![Alt text](https://www.codequoi.com/wp-content/uploads/2022/11/signal_vector_bits_fr.drawio.png)
> Exemple des vecteurs de 32 bits d’un processus. Ici, le signal 17, SIGCHLD, a été envoyé (donc mis en attente). De plus, ce même processus a précédemment indiqué qu’il bloque le signal 2, SIGINT.

Il est important de noter qu’il ne peut pas y avoir plusieurs signaux du même type en attente. Dans l’image ci-dessus, le processus a déjà le signal 17, SIGCHLD, en attente. Le système ne peut donc pas lui envoyer d’autres signaux SIGCHLD jusqu’à ce que ce signal soit réceptionné. Il n’y a pas non plus de file d’attente pour les signaux en attente : tant que ce signal n’est pas réceptionné, tous les signaux du même type qui suivent sont perdus.

# Envoyer un signal a un processus: Server

```c
int	kill(pid_t pid, int sig);
```

La fonction kill(); envoie un signal a un processus ou un groupe de processus en specifiant le PID.

- Le signal a envoyer est specifier par sig.
