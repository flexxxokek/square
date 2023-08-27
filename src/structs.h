#ifndef STRUCTS_
#define STRUCTS_

/// \brief структура, содержащая информацию о тесте и верные выходные данные
struct coeffStruct
{
    double a;
    double b;
    double c;
};


struct rootStruct
{
    double x1;
    double x2;
    int nRoots;
};


struct testStruct
{
    struct coeffStruct coeffs;
    struct rootStruct   roots;
    int num; ///< номер теста
};

#endif
