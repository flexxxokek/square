#ifndef TEST_DEF
#define TEST_DEF
    struct testStruct
    {
        double a, b, c;
        double xref1, xref2;
        int nRootsref;
        int num = 1;
    };
    bool runTest(struct testStruct test);
    void printFailTestInfo(struct testStruct test, double const x1, double const x2);
    void testAll(char* fileName);
#endif

