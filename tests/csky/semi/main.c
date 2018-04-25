#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
void test_open(void)
{
    FILE *f = fopen ("test1.txt", "w+");
    if (f == NULL) {
        printf ("open test1.txt(w+) failed.\n");
        return;
    }
    printf ("open test1.txt(w+) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "r");
    if (f == NULL) {
        printf ("open test1.txt(r) failed.\n");
        return;
    }
    printf ("open test1.txt(r) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "r+");
    if (f == NULL) {
        printf ("open test1.txt(r+) failed.\n");
        return;
    }
    printf ("open test1.txt(r+) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "w");
    if (f == NULL) {
        printf ("open test1.txt(w) failed.\n");
        return;
    }
    printf ("open test1.txt(w) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "a");
    if (f == NULL) {
        printf ("open test1.txt(a) failed.\n");
        return;
    }
    printf ("open test1.txt(a) \t\t-------- OK.\n");
    fclose(f);

    f = fopen ("test1.txt", "a+");
    if (f == NULL) {
        printf ("open test1.txt(a+) failed.\n");
        return;
    }
    printf ("open test1.txt(a+) \t\t-------- OK.\n");
    fclose(f);
}

void test_read_write (void)
{
    FILE *f = fopen ("test1.txt", "w+");
    char *text = "this string is written to a file\n";
    char buff[256];
    int ret;

    fwrite (text, strlen(text), 1, f);
    fclose(f);
    f = fopen("test1.txt", "r");
    memset(buff, 0, sizeof(buff));
    fread(buff, strlen(text), 1, f);

    if (strcmp (text, buff) == 0) {
        printf ("read write OK.\n");
    } else {
        printf ("read write failed.\n");
        printf ("Write: %s\n", text);
        printf ("Read: %s\n", buff);
    }
    ret = fseek(f, 0, SEEK_SET);
    memset(buff, 0 , sizeof(buff));
    fread(buff, strlen(text), 1, f);
    if (strcmp (text, buff) == 0) {
        printf ("fseek OK.\n");
    } else {
        printf ("fseek failed.\n");
        printf ("Write: %s\n", text);
        printf ("Read: %s\n", buff);
    }
    fclose (f);
}
int test_stat()
{
    int ret;
    struct stat st;
    ret = stat("test1.txt", &st);
    if (!ret) {
        printf("stat success\n");
    }
    return ret; 
}
int test_remove()
{
    int ret;
    ret = remove("test2.txt");
    if (!ret) {
        printf("remove success\n");
    }
    return ret; 
}
int test_system()
{
    int ret;
    ret = system("cp test1.txt test2.txt");
    if (!ret) {
        printf("system success\n");
    }
    return ret; 
}
int test_rename()
{
    int ret;
    ret = rename("test1.txt", "test3.txt");
    if (!ret) {
        printf("rename success\n");
    }
    return ret; 
}
int test_isatty()
{
  int ret;
  ret = isatty(0);
  if (ret == 1) {
    printf("isatty success\n");
  }
  return ret;
}
/*
int test_fstat()
{
    int ret, fd;
    struct stat st;
    fd = open("test3.txt", O_RDONLY, 0644);
    ret = fstat(fd, &st);
    if (!ret) {
        printf("fstat success\n");
    }
    close(fd); 
    return ret;
}
*/
int main(void)
{
    struct timeval val;
    struct stat    st;
    printf ("---------------- Semihosting Test --------------\n");
    gettimeofday(&val, NULL);
    printf("time: sizeof(timeval): %d, %lld, %lld\n", sizeof(struct timeval), val.tv_sec, val.tv_usec);
    test_open ();
    test_read_write();
    test_system();
    test_rename();
    test_remove();
    test_isatty();
    printf ("--------------- Semihosting Finish --------------\n");
    exit(0);
    return 0;   
}
