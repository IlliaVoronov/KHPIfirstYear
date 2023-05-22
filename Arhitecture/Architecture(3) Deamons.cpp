#include <iostream>
#include <signal.h>
#include <syslog.h>
#include <sys/stat.h>
#include <unistd.h>

void signal_handler(int signum) {
    switch(signum) {
        case SIGUSR1:
            syslog(LOG_INFO, "Received SIGUSR1 signal.");
            break;
        case SIGINT:
            syslog(LOG_INFO, "Received SIGINT signal. Terminating...");
            exit(EXIT_SUCCESS);
            break;
    }
}

int main() {
    pid_t pid, sid;
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    openlog("my_daemon", LOG_PID, LOG_DAEMON);
    syslog(LOG_INFO, "Daemon started.");
    signal(SIGUSR1, signal_handler);
    signal(SIGINT, signal_handler);
    while (true) {
        pause();
    }
    closelog();
    exit(EXIT_SUCCESS);
    return 0;
}

