#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

extern void executeGet(const std::string noun);
extern void executeDrop(const std::string noun);
extern void executeAsk(const std::string noun);
extern void executeGive(const std::string noun);
extern void executeInventory(void);

#endif