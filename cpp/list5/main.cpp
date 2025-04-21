#include "list.h"

int main(void)
{
    List list;
    initlist(&list);

    list.insertFirstNode(&list,4);   //[4]
    std::cout << list << std:endl;

    list.insertFirstNode(&list,3);   //[3,4]
    std::cout << list << std:endl;

    list.insertFirstNode(&list,1);   //[1,3,4]
    std::cout << list << std:endl;

    list.insertNode(&list,1,2);      //[1,2,3,4]
    std::cout << list << std:endl;

    list.deleteNode(&list,3);        //[1,2,4]
    std::cout << list << std:endl;
    
    // cleanuplist(&list);
    return 0;
}