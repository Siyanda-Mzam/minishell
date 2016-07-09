/************TESTS****************/
SET AND UNSET ENVIRONMENT

    if (putenv("TT=xxxxx") != 0)
        perror("putenv");

    system("echo '***** Environment before unsetenv(TT)'; "
            "printenv | grep ^TT");
    system("echo 'Total lines from printenv:' `printenv | wc -l`");

    unsetenv("TT");

    system("echo '***** Environment after unsetenv(TT)'; "
            "printenv | grep ^TT");
    system("echo 'Total lines from printenv:' `printenv | wc -l`");

    setenv("xyz", "one", 1);
    setenv("xyz", "two", 0);
    setenv("xyz2", "222", 0);

    system("echo '***** Environment after setenv() calls'; "
            "printenv | grep ^x");
    system("echo 'Total lines from printenv:' `printenv | wc -l`");
    
/**************END*****************/
