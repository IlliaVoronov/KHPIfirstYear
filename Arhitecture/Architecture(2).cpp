#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Command line arguments:" << endl;
    for (int i = 0; i < argc; i++) {
        cout << " " << argv[i];
    }
    cout << endl;

    cout << "Process ID (PID): " << getpid() << endl;
    cout << "Session ID (SID): " << getsid(0) << endl;
    cout << "Process Group ID (PGID): " << getpgid(0) << endl;
    cout << "Parent Process ID (PPID): " << getppid() << endl;

    struct passwd* user_info = getpwuid(getuid());
    if (user_info != NULL) {
        cout << "Username: " << user_info->pw_name << endl;
        struct group* group_info = getgrgid(user_info->pw_gid);
        if (group_info != NULL) {
            cout << "Group: " << group_info->gr_name << endl;
        } else {
            cout << "Failed to get group information" << endl;
        }
    } else {
        cout << "Failed to get user information" << endl;
    }

    return EXIT_SUCCESS;
}
