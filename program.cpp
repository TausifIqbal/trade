#include "../include/trade.h"
#include <vector>
int main(){

    std::vector<trade::Order> orders{
        {1,10,100.0,"APPL","BL"},
        {2,5,105.0,"APPL","BL"},
        {3,15,102.0,"APPL","BL"},
        {4,15,98.0,"APPL","BL"},
        {5,10,200.0,"GOOG","BL"},
        {6,15,201.0,"GOOG","BL"},
        {7,10,198.0,"GOOG","BL"}
    };
    for(auto &order: orders){
        trade::addOrder(order);
    }

    std::vector<trade::Tick> ticks{
        {"08:58", 106.0, "APPL"},
        {"09:00", 104.0, "APPL"},
        {"09:01", 102.0, "APPL"},
        {"09:02", 98.0, "APPL"},
        {"09:03", 200.0, "GOOG"}
    };
    for(auto &tick: ticks){
        trade::newTick(tick);
    }

    return 0;
}