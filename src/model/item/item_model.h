//
// Created by Stefano on 2/18/2023.
//

#ifndef AABRHAM_SRC_MODEL_ITEM_ITEM_MODEL_H_
#define AABRHAM_SRC_MODEL_ITEM_ITEM_MODEL_H_

#include <crow.h>
#include <string>
#include "../../infrastructure/redis/redis.h"

namespace item {
static const std::string kQuestionEvalKey = "question:eval";
crow::json::wvalue InsertItem(const crow::json::rvalue &item_data, const std::string &username);
crow::json::wvalue GetItems(const std::string &username);
long GetDelay(const crow::json::rvalue &values);
int GetNumberOfHoursCorrespondingToAnswer(const std::string &key, const crow::json::rvalue &);
}
#endif //AABRHAM_SRC_MODEL_ITEM_ITEM_MODEL_H_
