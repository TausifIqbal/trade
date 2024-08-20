#pragma once
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
namespace trade {
    class Order;
    class Tick;

    void addOrder(Order &order);
    
    void newTick(Tick &tick);

    

    class Tick{
        public:
            Tick( std::string &&time_stamp, double price, std::string &&symbol):
            _time_stamp(std::move(time_stamp)), _price(price), _symbol(std::move(symbol)) {
            };
            void print()const{
                std::cout << "Time: " << _time_stamp << " Price: " << _price << " Symbol: " << _symbol << std::endl;
            }
            std::string getSymbol()const{
                return _symbol;
            }
            int getPrice()const{
                return _price;
            }
            std::string getTime()const{
                return _time_stamp;
            }


        private:
            std::string _time_stamp{}; 
            double _price{};
            std::string _symbol{};
    };

    class Order {

        public:
            Order( int order_id, int quantity, double ordered_price, std::string &&symbol ,std::string &&type):
            _order_id(order_id), _quantity(quantity), _ordered_price(ordered_price),_symbol(std::move(symbol)) , _type(std::move(type)) {                
            };

            std::string getSymbol()const{
                return _symbol;
            }
            int getOrderID()const{
                return _order_id;
            }
            std::string getType()const{
                return _type;
            }
            int getQuantity()const{
                return _quantity;
            }
            int getPrice()const{
                return _ordered_price;
            }
            bool operator<(const Order &order) const{
                return _ordered_price > order._ordered_price;
            }

            void print()const{
                std::cout << "Order ID: " << _order_id << " Quantity: " << _quantity <<   " Symbol: " << _symbol<<" Price: " << _ordered_price << " Type: " << _type << std::endl;
            }

        private:
            int _order_id{};
            int _quantity{};
            double _ordered_price{};
            std::string _symbol{};
            std::string _type{};
    };
}