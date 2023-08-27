#ifndef TEST_DEF
#define TEST_DEF

#define kindAssert(expr)                            \
if(!(expr))                                         \
{                                                   \
    printf( "\n\n\nTROUBLE HAS CAME!\n"                  \
            "file:%s, line:%d, function:%s\n\n",  \
            __FILE__, __LINE__, __FUNCTION__);      \
}                                                   

/**
    * \brief считывает информацию о тесте из файла
    * \param test указатель на структуру, содержащую информацию о тесте и верные выходные данные
    * \param fp указатель на файл
    * \return взовращает false при неправильном формате файла или по достижении конца файла,
    * возвращает true при успешном прочтении файла
    */
bool fscanTest(struct testStruct* test, FILE* fp);

/**
    * \brief запуск одного теста
    * \param test структура, содержащая информацию о тесте и верные выходные данные
    * \return возвращает false если тест удачно прошел проверку, true если нет
    */
bool runTest(struct testStruct test);

/**
    * \brief выводит сообщение о проваленном тесте в командную строку
    * \param[in] test структура, содержащая информацию о тесте и верные выходные данные
    * \param[in] x1, x2 полученные программой корни
    * \param[in] nRoots количество полученных программой корней
    */
void printFailTestInfo(struct testStruct test, struct rootStruct wrongRoots);

/**
    * \brief обрабатывает и проверяет тесты из файла
    *(чтобы функция прочла файл он в нем должна быть строчка Daniel_tests)
    * \param fileName имя файла
    */
void testAll(char* fileName);

#endif

