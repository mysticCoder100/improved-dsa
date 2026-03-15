#include <iostream>
#include "singly_list.h"
//
// Created by abdul on 05/03/2026.
//

void singlyDemo() {
    SinglyLinkList<int> list;

    list.addTail(3);
    list.addTail(4);
    list.addHead(8);

    list.deleteFromTail();
    std::cout << static_cast<int>(list.inList(4)) << std::endl;
}

