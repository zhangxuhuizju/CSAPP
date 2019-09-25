#include "csapp.h"
#define MAXARGS 128

void eval(char* cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main() {
    char cmdline[MAXARGS];      //command line

    while (1) {
        printf("> ");
        Fgets(cmdline, MAXARGS, stdin);
        if (feof(stdin))
            exit(0);

        eval(cmdline);
    }
}

/**
 * evaluate a command line
 */
void eval(char *cmdline) {
    char *argv[MAXARGS];                //argument list execve(filename, argv, envp)
    char buf[MAXLINE];                  //holds modified command line
    int bg;                             //should the job run in bg or fg?
    pid_t pid;                          //process pid
    
    strcpy(buf, cmdline);
    bg = parseline(buf, argv);

    if(argv[0] == NULL)
        return;                         //ignore empty lines
    
    if (!builtin_command(argv)) {
        if ((pid = Fork()) == 0) {      //child runs user job
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");
        } else
            printf("%d %s", pid, cmdline);
    }
    return;
}

/**
 * if first arg is a builtin command, run it and return true
 */ 
int builtin_command(char **argv) {
    if (strcmp(argv[0], "quit") == 0)
        exit(0);
    if (strcmp(argv[0], "&") == 0)
        return 1;
    
    return 0;
}

/**
 * parse the command line and build the argv array
 */
int parseline(char *buf, char **argv) {
    char *delim;                        //point to the first space delimiter
    int argc;                           //number of argvs
    int bg;

    buf[strlen(buf)-1] = ' ';           //replace the trailing '\n' with space
    while (*buf && (*buf == ' '))
        buf++;
    
    //build the argv list
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))   //ignore spaces
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)                      //ignore blank line
        return 1;
    
    if ((bg = (*argv[argc-1] == '&')) != 0)
        argv[--argc] = NULL;
    
    return bg;
}