#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: ./launch-app <-w|-f> executable" << endl;
        return EXIT_FAILURE;
    }

    int status;
    pid_t pid;

    if (strcmp(argv[1], "-w") == 0) {
        pid = fork();
        if (pid < 0) {
            cerr << "Failed to fork process" << endl;
            return EXIT_FAILURE;
        } else if (pid == 0) {
            // Child process
            execlp(argv[2], argv[2], NULL);
            cerr << "Failed to execute " << argv[2] << endl;
            return EXIT_FAILURE;
        } else {
            // Parent process
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                cout << "Application exited with code " << WEXITSTATUS(status) << endl;
            } else if (WIFSIGNALED(status)) {
                cout << "Application terminated with signal " << WTERMSIG(status) << endl;
            }
        }
    } else if (strcmp(argv[1], "-f") == 0) {
        pid = fork();
        if (pid < 0) {
            cerr << "Failed to fork process" << endl;
            return EXIT_FAILURE;
        } else if (pid == 0) {
            // Child process
            setsid();
            execlp(argv[2], argv[2], NULL);
            cerr << "Failed to execute " << argv[2] << endl;
            return EXIT_FAILURE;
        } else {
            // Parent process
            cout << "Application started with PID " << pid << endl;
        }
    } else {
        cerr << "Invalid argument: " << argv[1] << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
