/***********************************************************************
 *
 * Name       : Aritra Sarkar, Anish Das, Dripta Patra
 * Roll No.   : 002311001048, 002311001009, 002311001006
 * Team No.   : 04
 * Group      : A1
 * Date       : 30-10-2025
 *
 * 
 * Description: Using the fork system call, create two Child Processes - Child1 and
 *              Child2. Transfer 1GB file from the Parent Process to the Child1
 *              Process using a FIFO. Lets call this FIFO as FIFO1. Now, the Child1
 *              process should transfer the same file from the Child1 Process to the
 *              Child2 Process using another FIFO. Let's call this FIFO as FIFO2.
 *              And ultimately, the last transfer will take place from the Child2
 *              process to the Parent process via FIFO3. Please note and print the
 *              time required to do this triple transfer. Attach this output to the source
 *              file as a comment.
 *              Once the Parent process gets back the same file, this file needs to be
 *              compared with the original file(use cmp or diff command) to make
 *              sure that the same file has returned back.
 *              To create FIFO, you can either use a shell command or a system call.
 *              To create a large file you can use the relevant command.
 *              Use ‘ls –l’ command to show the FIFO and the large files. Attach this
 *              output to the source file as a comment.
 *              Make sure that the starting comment block has all the necessary
 *              information attached.
 *              Please NOTE, no intermediate file copy will be allowed anywhere in
 *              either of the Child processes - Child1 or Child2.
 *              Also, credit will be given to those who can do the transfer in the
 *              shortest possible time.
 *              Please do note also, this program should be written in C.
 * 
 *
 * Compilation Command:
 *     gcc A1_04_8T_FIFO.c -o A1_04_8T_FIFO
 *
 * Execution Sequence:
 *     ./A1_04_8T_FIFO
 *
 * Sample Output:
 *           === FIFO File Transfer System ===
 *          
 *          Using existing test file: test_file.dat
 *          FIFOs created successfully.
 *          
 *          === File and FIFO Listing ===
 *          prw-rw-r-- 1 adminpc adminpc    0 Oct 30 13:02 fifo1
 *          prw-rw-r-- 1 adminpc adminpc    0 Oct 30 13:02 fifo2
 *          prw-rw-r-- 1 adminpc adminpc    0 Oct 30 13:02 fifo3
 *          -rw-rw-r-- 1 adminpc adminpc 1.0G Oct 30 12:32 test_file.dat
 *          
 *          Transferring file through FIFO pipeline...
 *          Parent -> Child1 -> Child2 -> Parent
 *          
 *          
 *          === PERFORMANCE OUTPUT ===
 *          Time for Parent -> Child1 (FIFO1 write): 0.531489 seconds
 *          Time for Child1 -> Child2 (FIFO2 transfer): 0.531531 seconds
 *          Time for Child2 -> Parent (FIFO3 read/write): 0.531482 seconds
 *          Total wall-clock time: 1.174972 seconds
 *          Overall transfer rate: 871.51 MB/s
 *          
 *          === File Comparison ===
 *          SUCCESS: Files are identical!
 *          
 *          === Final File Listing ===
 *          -rw-r--r-- 1 adminpc adminpc 1.0G Oct 30 13:02 received_file.dat
 *          -rw-rw-r-- 1 adminpc adminpc 1.0G Oct 30 12:32 test_file.dat
 *          
 *          FIFOs cleaned up.
 *          Program completed.
 *
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define FIFO3 "fifo3"
#define SOURCE_FILE "test_file.dat"
#define DEST_FILE "received_file.dat"
#define BUFFER_SIZE (1024 * 1024)           /* 1MB buffer for optimal performance */
#define FILE_SIZE (1024LL * 1024LL * 1024LL) /* 1GB */

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

void create_test_file() {
    printf("Creating 1GB test file...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "dd if=/dev/urandom of=%s bs=1M count=1024 status=none", SOURCE_FILE);
    int ret = system(cmd);
    if (ret != 0) {
        fprintf(stderr, "Warning: dd returned non-zero status (%d).\n", ret);
    } else {
        printf("Test file created: %s\n", SOURCE_FILE);
    }
}

void create_fifos() {
    unlink(FIFO1);
    unlink(FIFO2);
    unlink(FIFO3);

    if (mkfifo(FIFO1, 0666) == -1) {
        fprintf(stderr, "mkfifo(%s) failed: %s\n", FIFO1, strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (mkfifo(FIFO2, 0666) == -1) {
        fprintf(stderr, "mkfifo(%s) failed: %s\n", FIFO2, strerror(errno));
        unlink(FIFO1);
        exit(EXIT_FAILURE);
    }
    if (mkfifo(FIFO3, 0666) == -1) {
        fprintf(stderr, "mkfifo(%s) failed: %s\n", FIFO3, strerror(errno));
        unlink(FIFO1);
        unlink(FIFO2);
        exit(EXIT_FAILURE);
    }
    printf("FIFOs created successfully.\n");
}

ssize_t transfer_through_fifo(int fd_in, int fd_out, char *buffer) {
    ssize_t bytes_read, bytes_written;
    ssize_t total_bytes = 0;

    while ((bytes_read = read(fd_in, buffer, BUFFER_SIZE)) > 0) {
        ssize_t written = 0;
        while (written < bytes_read) {
            ssize_t result = write(fd_out, buffer + written, bytes_read - written);
            if (result == -1) {
                if (errno == EINTR) continue;
                perror("write failed");
                return -1;
            }
            written += result;
        }
        total_bytes += bytes_read;
    }

    if (bytes_read == -1) {
        perror("read failed");
        return -1;
    }

    return total_bytes;
}

/* Helper to read a time value (as double) from a pipe fd */
void read_time_from_pipe_func(int fd, double *out) {
    char buf[64];
    ssize_t r = read(fd, buf, sizeof(buf) - 1);
    if (r > 0) {
        buf[r] = '\0';
        *out = atof(buf);
    } else {
        *out = -1.0;
    }
}

int main() {
    pid_t child1_pid, child2_pid, writer_pid;
    int status;
    char *buffer;

    int p_writer[2], p_child1[2], p_child2[2];
    if (pipe(p_writer) == -1 || pipe(p_child1) == -1 || pipe(p_child2) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    printf("=== FIFO File Transfer System ===\n\n");

    if (access(SOURCE_FILE, F_OK) != 0)
        create_test_file();
    else
        printf("Using existing test file: %s\n", SOURCE_FILE);

    create_fifos();

    printf("\n=== File and FIFO Listing ===\n");
    system("ls -lh fifo1 fifo2 fifo3 test_file.dat 2>/dev/null || true");
    printf("\n");

    double overall_start = get_time();

    /* Child1 */
    child1_pid = fork();
    if (child1_pid == -1) {
        perror("fork failed for child1");
        exit(EXIT_FAILURE);
    }

    if (child1_pid == 0) {
        close(p_child1[0]);
        close(p_writer[0]); close(p_writer[1]);
        close(p_child2[0]); close(p_child2[1]);

        int fd_fifo1 = open(FIFO1, O_RDONLY);
        if (fd_fifo1 == -1) {
            perror("Child1: open FIFO1 failed");
            dprintf(p_child1[1], "-1\n");
            _exit(EXIT_FAILURE);
        }

        int fd_fifo2 = open(FIFO2, O_WRONLY);
        if (fd_fifo2 == -1) {
            perror("Child1: open FIFO2 failed");
            close(fd_fifo1);
            dprintf(p_child1[1], "-1\n");
            _exit(EXIT_FAILURE);
        }

        double t0 = get_time();
        ssize_t transferred = transfer_through_fifo(fd_fifo1, fd_fifo2, buffer);
        double t1 = get_time();

        if (transferred < 0)
            dprintf(p_child1[1], "-1\n");
        else
            dprintf(p_child1[1], "%.6f\n", t1 - t0);

        close(fd_fifo1);
        close(fd_fifo2);
        close(p_child1[1]);
        free(buffer);
        _exit(EXIT_SUCCESS);
    }

    /* Child2 */
    child2_pid = fork();
    if (child2_pid == -1) {
        perror("fork failed for child2");
        exit(EXIT_FAILURE);
    }

    if (child2_pid == 0) {
        close(p_child2[0]);
        close(p_writer[0]); close(p_writer[1]);
        close(p_child1[0]); close(p_child1[1]);

        int fd_fifo2 = open(FIFO2, O_RDONLY);
        if (fd_fifo2 == -1) {
            perror("Child2: open FIFO2 failed");
            dprintf(p_child2[1], "-1\n");
            _exit(EXIT_FAILURE);
        }

        int fd_fifo3 = open(FIFO3, O_WRONLY);
        if (fd_fifo3 == -1) {
            perror("Child2: open FIFO3 failed");
            close(fd_fifo2);
            dprintf(p_child2[1], "-1\n");
            _exit(EXIT_FAILURE);
        }

        double t0 = get_time();
        ssize_t transferred = transfer_through_fifo(fd_fifo2, fd_fifo3, buffer);
        double t1 = get_time();

        if (transferred < 0)
            dprintf(p_child2[1], "-1\n");
        else
            dprintf(p_child2[1], "%.6f\n", t1 - t0);

        close(fd_fifo2);
        close(fd_fifo3);
        close(p_child2[1]);
        free(buffer);
        _exit(EXIT_SUCCESS);
    }

    printf("Transferring file through FIFO pipeline...\n");
    printf("Parent -> Child1 -> Child2 -> Parent\n\n");

    /* Writer process */
    writer_pid = fork();
    if (writer_pid == -1) {
        perror("fork failed for writer");
        exit(EXIT_FAILURE);
    }

    if (writer_pid == 0) {
        close(p_writer[0]);
        close(p_child1[0]); close(p_child1[1]);
        close(p_child2[0]); close(p_child2[1]);

        int fd_source = open(SOURCE_FILE, O_RDONLY);
        if (fd_source == -1) {
            perror("Writer: open source file failed");
            dprintf(p_writer[1], "-1\n");
            _exit(EXIT_FAILURE);
        }

        int fd_fifo1 = open(FIFO1, O_WRONLY);
        if (fd_fifo1 == -1) {
            perror("Writer: open FIFO1 failed");
            close(fd_source);
            dprintf(p_writer[1], "-1\n");
            _exit(EXIT_FAILURE);
        }

        double t0 = get_time();
        ssize_t transferred = transfer_through_fifo(fd_source, fd_fifo1, buffer);
        double t1 = get_time();

        if (transferred < 0)
            dprintf(p_writer[1], "-1\n");
        else
            dprintf(p_writer[1], "%.6f\n", t1 - t0);

        close(fd_source);
        close(fd_fifo1);
        close(p_writer[1]);
        free(buffer);
        _exit(EXIT_SUCCESS);
    }

    /* Parent reads FIFO3 -> DEST_FILE */
    close(p_writer[1]);
    close(p_child1[1]);
    close(p_child2[1]);

    int fd_fifo3 = open(FIFO3, O_RDONLY);
    if (fd_fifo3 == -1) {
        perror("Parent: open FIFO3 failed");
        exit(EXIT_FAILURE);
    }

    int fd_dest = open(DEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1) {
        perror("Parent: open destination file failed");
        close(fd_fifo3);
        exit(EXIT_FAILURE);
    }

    double parent_t0 = get_time();
    ssize_t parent_transferred = transfer_through_fifo(fd_fifo3, fd_dest, buffer);
    double parent_t1 = get_time();

    close(fd_fifo3);
    close(fd_dest);

    waitpid(writer_pid, &status, 0);
    waitpid(child1_pid, &status, 0);
    waitpid(child2_pid, &status, 0);

    double t_writer = -1.0, t_child1 = -1.0, t_child2 = -1.0;

    read_time_from_pipe_func(p_writer[0], &t_writer);
    read_time_from_pipe_func(p_child1[0], &t_child1);
    read_time_from_pipe_func(p_child2[0], &t_child2);

    close(p_writer[0]);
    close(p_child1[0]);
    close(p_child2[0]);

    double overall_end = get_time();
    double total_time = overall_end - overall_start;

    if (t_child2 < 0)
        t_child2 = parent_t1 - parent_t0;

    printf("\n=== PERFORMANCE OUTPUT ===\n");
    if (t_writer >= 0)
        printf("Time for Parent -> Child1 (FIFO1 write): %.6f seconds\n", t_writer);
    else
        printf("Time for Parent -> Child1 (FIFO1 write): (unavailable)\n");

    if (t_child1 >= 0)
        printf("Time for Child1 -> Child2 (FIFO2 transfer): %.6f seconds\n", t_child1);
    else
        printf("Time for Child1 -> Child2 (FIFO2 transfer): (unavailable)\n");

    if (t_child2 >= 0)
        printf("Time for Child2 -> Parent (FIFO3 read/write): %.6f seconds\n", t_child2);
    else
        printf("Time for Child2 -> Parent (FIFO3 read/write): (unavailable)\n");

    printf("Total wall-clock time: %.6f seconds\n", total_time);

    double transfer_rate_mb_s = 0.0;
    if (total_time > 0.0) {
        transfer_rate_mb_s = (FILE_SIZE / (1024.0 * 1024.0)) / total_time;
        printf("Overall transfer rate: %.2f MB/s\n", transfer_rate_mb_s);
    }

    printf("\n=== File Comparison ===\n");
    int cmp_res = system("cmp test_file.dat received_file.dat >/dev/null 2>&1");
    if (cmp_res == 0)
        printf("SUCCESS: Files are identical!\n");
    else
        printf("ERROR: Files differ or cmp failed (exit code: %d)\n", cmp_res);

    printf("\n=== Final File Listing ===\n");
    system("ls -lh test_file.dat received_file.dat 2>/dev/null || true");

    unlink(FIFO1);
    unlink(FIFO2);
    unlink(FIFO3);
    free(buffer);

    printf("\nFIFOs cleaned up.\n");
    printf("Program completed.\n");

    return 0;
}