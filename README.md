# Trade

## Logic

    Store all orders in a order_book. Order_book is a map of symbol and order objects
    Order_Book unorder_map<string,multiset<Order>>
        map of symbol and the orders
        APPL --> {all orders associated with APPL}
    
    for tick event
    extract symbol from tick and get corresponding orders from the map
    if condition for Buying Limit is satisfied then put the order in a vector
    finally execute all the orders stored in the vector

    only BuyLimit logic is implemented
    logic for BL
    iterate through the mulitset of orders for the symbol in tick
    orders are stored in descending fashion
    pull out all the orders having price more than that of tick price
    and store in a vector 


## Directory structure
    program.cpp
    src
        - trade.cpp
    include
        - trade.h
    README.md

## To run
    from root directory  run
    g++ -Iinclude src/trade.cpp program.cpp -o prog_app
