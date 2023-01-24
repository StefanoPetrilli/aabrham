//
// Created by Stefano on 1/24/2023.
//

#ifndef AABRHAM_SRC_CONTROLLER_INDEX_INDEX_CONTROLLER_H_
#define AABRHAM_SRC_CONTROLLER_INDEX_INDEX_CONTROLLER_H_
#include "crow.h"

namespace indexx { //It is not possible to use index as there is a namespace conflict in the crows library
void AddIndexController(crow::SimpleApp* app);
}
#endif //AABRHAM_SRC_CONTROLLER_INDEX_INDEX_CONTROLLER_H_
