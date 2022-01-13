/*
 *  TicketMachine.h
 *
 *  Created on: 2022-01-14
 *      Author: deft
 */

#ifndef TICKETMACHINE_H_
#define TICKETMACHINE_H_

class TicketMachine
{
public:
    TicketMachine(/* args */);
    virtual ~TicketMachine();
    void showPrompt();
    void insertMoney(int money);
    void showBalance();
    void printTicket();
    void showTotal();
private:
    const int PRICE;
    int balance;
    int total;
};

#endif  /* TICKETMACHINE_H_ */