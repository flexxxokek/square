#ifndef CONSTANT_H
#define CONSTANT_H
    const double D_DIFFER = 0.0001;
    enum ROOTS { NOROOTS = 0, ONEROOT, TWOROOTS, INFROOTS = -1};
    const int MAXROOTS = 2;
    const int COEFFSNUM = MAXROOTS + 1;
    const char OPTIONS[2][7] = {"--help",
                                "--test"};
#endif


