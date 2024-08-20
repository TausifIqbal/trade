#include "../include/trade.h"
#include <vector>
namespace trade{
    std::unordered_map<std::string, std::multiset<Order>> order_book;

    void executeOrder(Order  &order , Tick &tick){
        auto symbol_orders = order_book.find(order.getSymbol());
        // check if the order exists 
        if(symbol_orders == order_book.end()){
            return;
        }
        // remove order from the order book of that symbol
        if(symbol_orders->second.find(order) != symbol_orders->second.end()){
            symbol_orders->second.erase(order);
            std::cout<<"Order  "<<order.getOrderID()<<" executed at "<< tick.getTime() <<" price: "<<tick.getPrice()<<" Quantity :"<< order.getQuantity() <<"\n";
        }

    }

    void addOrder(Order &order){
        auto orders = order_book.find(order.getSymbol());
        if(orders == order_book.end()){
            order_book[order.getSymbol()] = std::multiset<Order>{order};
        }else{
            orders->second.insert(order);
        }
    }
    void newTick(Tick &tick){
        auto price = tick.getPrice();
        auto symbol = tick.getSymbol();

        //get order book for that symbol
        auto symbol_orders = order_book.find(symbol);
        if(symbol_orders == order_book.end()){
            return;
        }

        std::vector<Order> orderToExecute ;

        // BL: for each order in the symbol_orders if price is less 
        for(auto &symbol_order: symbol_orders->second){
            if(symbol_order.getPrice() >= price && symbol_order.getType() == "BL"){
                orderToExecute.push_back(symbol_order);
            }else{
                break;
            }
        }
        
        for(auto &order: orderToExecute){
            executeOrder(order,tick);
        }        
    }

  
  
}