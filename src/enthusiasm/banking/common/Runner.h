//
// Created by 홍준근 on 2023/01/25.
//

#ifndef FIRSTCPP_RUNNER_H
#define FIRSTCPP_RUNNER_H

#include <iostream>
#include "enthusiasm/banking/common/Exception.h"
#include "enthusiasm/banking/command/service/BankService.h"
#include "enthusiasm/banking/common/ViewManager.h"
#include "enthusiasm/banking/ui/includes/View.h"
#include "BankViewManager.h"
#include "BankViewFactory.h"

class IRunner {
protected:
    virtual void preprocess() = 0;

    virtual void businessLogic() = 0;

    virtual void hook() = 0;

public:
    void run() {
        preprocess();
        while (true) {
            try {
                businessLogic();
            } catch(DuplicatedViewEntityException& e){
                std::cout<<"DuplicatedViewEntityException: "<<e.getReason()<<std::endl;
            }catch (WithdrawException& e) {
                std::cout<<"WithdrawException: "<<e.getReason()<<std::endl;
            } catch (DepositException& e) {
                std::cout<<"DepositException: "<<e.getReason()<<std::endl;
            } catch (AccountSystemException& e) {
                std::cout<<"AccountSystemException: "<<e.getReason()<<std::endl;
            } catch(SystemCallException& e){
                std::cout<<"SystemCallException: "<<e.getReason()<<std::endl;
                break;
            }
        }
        hook();
    }
};

class BankServiceRunner : public IRunner {
private:
    BankService* bankService;
protected:
    void preprocess() override{
        std::cout<<"BankService Start"<<std::endl;
    };

    void businessLogic()override{
        ViewManager* vm = new BankViewManager(new BankViewFactory(bankService));
        vm->getTo(ViewID(utils::Parser::viewTypeToConstLong(eViewType::MainMenu)));
        delete vm;
    };

    void hook() override{
        std::cout<<"BankService Done"<<std::endl;
    };
public:
    BankServiceRunner(const BankService& bankService)
    :bankService(new BankService(bankService)){}
};
#endif //FIRSTCPP_RUNNER_H
