//
// Created by Stefano on 2/18/2023.
//

#ifndef AABRHAM_SRC_MODEL_ITEM_ITEM_MODEL_H_
#define AABRHAM_SRC_MODEL_ITEM_ITEM_MODEL_H_

#include <crow.h>
#include <string>
#include "../../infrastructure/redis/redis.h"

namespace item {
crow::json::wvalue InsertItem(std::string product_name, std::string username);
}
#endif //AABRHAM_SRC_MODEL_ITEM_ITEM_MODEL_H_
